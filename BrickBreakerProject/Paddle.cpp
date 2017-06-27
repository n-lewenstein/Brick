#include "Paddle.h"
#include "Constants.h"

Paddle::Paddle()
	:
	Animation(sizes::pd_frm_wd, sizes::pd_frm_ht, sizes::pd_txtr_wd, sizes::pd_txtr_ht, sf::seconds(0.5))
{
	Animation::start();
	textures::pd_txtr.loadFromFile(paths::pad_path);
	Drawable::m_sprite.setTexture(textures::pd_txtr);
	Drawable::m_sprite.setPosition(sizes::win_wd / 2 - sizes::pd_frm_wd/2, 7*(sizes::win_ht / 8));
}

Paddle::~Paddle()
{}

void Paddle::draw(sf::RenderWindow & win)
{
	Drawable::m_sprite.setTextureRect(Animation::nextFrame());
	win.draw(Drawable::m_sprite);
}

bool Paddle::contains(const sf::Vector2f & point) const
{
	return Drawable::m_sprite.getGlobalBounds().contains(point);
}

void Paddle::expand(float mul)
{
	Drawable::m_sprite.scale({ mul, 1 });
}

Direction<float> Paddle::calc(const Collision & collision)
{
	float newAngle;

	newAngle = sizes::min_angle + collision.relativeHit * ((180.0 - 2 * (sizes::min_angle)) / 100) + 180.0;
	return Direction<float>(newAngle);
}

void Paddle::move()
{
	Drawable::m_sprite.move({ float(Movable::getSpeed() * Movable::getDirection()), 0.0 });
}
