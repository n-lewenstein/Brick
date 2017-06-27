#include "SlowBall.h"
#include "Board.h"


SlowBall::SlowBall(const sf::Vector2f & pos)
	:
	FallingObject(pos)
{
	if (textures::slw_txtr.getNativeHandle() == 0)
		textures::slw_txtr.loadFromFile(paths::fo_slw_path);

	Drawable::m_sprite.setTexture(textures::slw_txtr);
}

SlowBall::~SlowBall()
{}

void SlowBall::action(Board & brd)
{
	auto speedDown = [](Ball & bl)
	{
		bl.setSpeed(bl.getSpeed() - 0.2f);
	};

	std::for_each(brd.m_balls.begin(), brd.m_balls.end(), speedDown);
}
