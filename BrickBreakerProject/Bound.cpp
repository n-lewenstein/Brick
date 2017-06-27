#include "Bound.h"
#include "Constants.h"

Bound::Bound()
{
	m_bounds = sf::IntRect{ sizes::bnd_x, sizes::bnd_y, sizes::bnd_wd, sizes::bnd_ht };
}

Bound::~Bound()
{}

Direction<float> Bound::calc(const Collision & collision)
{
	float newAngle;

	//	The angle calculation varies according to the geometric position of the object.
	if (collision.orient == HV::Vertical)
	{
		newAngle = 180 - collision.hittingObjDir.getDirection();

		if (collision.hittingObjDir.getDirection() > 180)
			newAngle += 360;
	}
	else
	{
		newAngle = 360 - collision.hittingObjDir.getDirection();
	}

	return Direction<float>(newAngle);
}

void Bound::draw(sf::RenderWindow & win)
{
	win.draw(Drawable::m_sprite);
}

bool Bound::contains(const sf::Vector2f & point) const
{
	return m_bounds.contains(sf::Vector2i{ point });
}
