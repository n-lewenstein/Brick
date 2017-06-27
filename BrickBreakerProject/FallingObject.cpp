#include "FallingObject.h"
#include "Constants.h"
#include "Paddle.h"
#include "Bound.h"

FallingObject::FallingObject()
{}

FallingObject::FallingObject(const sf::Vector2f & pos)
	:
	Drawable(values::fall_val),
	Animation(sizes::fo_frm_wd, sizes::fo_frm_ht, sizes::fo_txtr_wd, sizes::fo_txtr_ht, sf::seconds(0.015f))
{
	Drawable::m_sprite.setPosition(pos);
	Movable::setSpeed(0.4f);
	Movable::setDirection(Direction<UD>(UD::Down));
	Animation::setRepeat(false);
}

FallingObject::~FallingObject()
{}

void FallingObject::draw(sf::RenderWindow & win)
{
	Drawable::m_sprite.setTextureRect(Animation::nextFrame());
	win.draw(Drawable::m_sprite);
}

bool FallingObject::contains(const sf::Vector2f & point) const
{
	return Drawable::m_sprite.getGlobalBounds().contains(point);
}

void FallingObject::move()
{
	Drawable::m_sprite.move({ 0.0, Movable::getDirection() * Movable::getSpeed() });
}

Collision FallingObject::collide(const Paddle & pad)
{
	Collision clsn;
	sf::FloatRect bounds(Drawable::bounds());
	
	//	4 corners of the falling-object.
	sf::Vector2f topLeft{ bounds.left,bounds.top };
	sf::Vector2f topRight{ bounds.left + bounds.width,bounds.top };
	sf::Vector2f btmLeft{ bounds.left, bounds.top + bounds.height };
	sf::Vector2f btmRight{ bounds.left + bounds.width, bounds.top + bounds.height };

	clsn.collide = (pad.contains(topLeft) || pad.contains(topRight) || pad.contains(btmLeft) || pad.contains(btmRight));

	return clsn;
}

Collision FallingObject::collide(const Bound & bnd)
{
	Collision clsn;
	sf::FloatRect bounds(Drawable::bounds());

	//	4 corners of the falling-object.
	sf::Vector2f topLeft{ bounds.left,bounds.top };
	sf::Vector2f topRight{ bounds.left + bounds.width,bounds.top };
	sf::Vector2f btmLeft{ bounds.left, bounds.top + bounds.height };
	sf::Vector2f btmRight{ bounds.left + bounds.width, bounds.top + bounds.height };

	clsn.collide = (!bnd.contains(topLeft) || !bnd.contains(topRight) || !bnd.contains(btmLeft) || !bnd.contains(btmRight));

	return clsn;
}
