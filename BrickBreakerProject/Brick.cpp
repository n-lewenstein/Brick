#include "Brick.h"

Brick::Brick(const sf::Vector2f & pos, int hits)
	:
	Drawable(values::brick_val),
	Animation(sizes::brk_frm_wd, sizes::brk_frm_ht, sizes::brk_txtr_wd, sizes::brk_txtr_ht),
	m_hitsLeft(hits)
{
	Animation::stop();

	if (textures::br_txtr.getNativeHandle() == 0)
		textures::br_txtr.loadFromFile(paths::br_path);

	Drawable::m_sprite.setPosition(pos);
	Drawable::m_sprite.setTexture(textures::br_txtr);
}

Brick::~Brick()
{}

void Brick::draw(sf::RenderWindow & win)
{
	Drawable::m_sprite.setTextureRect(Animation::nextFrame());
	win.draw(m_sprite);
}

bool Brick::contains(const sf::Vector2f & point) const
{
	return Drawable::m_sprite.getGlobalBounds().contains(point);
}

Direction<float> Brick::calc(const Collision & collision)
{
	float newAngle;

	//	The angle calculation varies according to the geometric position of the object.
	if (collision.orient == HV::Vertical)
	{
		newAngle = 180.0 - collision.hittingObjDir.getDirection();

		if (collision.hittingObjDir.getDirection() > 180.0)
			newAngle += 360.0;
	}
	else
	{
		newAngle = 360.0 - collision.hittingObjDir.getDirection();
	}

	return Direction<float>(newAngle);
}

void Brick::hit()
{
	m_hitsLeft--;
	Animation::step();
}

int Brick::hitsLeft() const
{
	return m_hitsLeft;
}
