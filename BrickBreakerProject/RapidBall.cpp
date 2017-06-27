#include "RapidBall.h"
#include "Board.h"


RapidBall::RapidBall(const sf::Vector2f & pos)
	:
	FallingObject(pos)
{
	if (textures::rpd_txtr.getNativeHandle() == 0)
		textures::rpd_txtr.loadFromFile(paths::fo_rpd_path);

	Drawable::m_sprite.setTexture(textures::rpd_txtr);
}

RapidBall::~RapidBall()
{}

void RapidBall::action(Board & brd)
{
	auto speedUp = [](Ball & bl) 
	{
		bl.setSpeed(bl.getSpeed() + 0.2f);
	};

	std::for_each(brd.m_balls.begin(), brd.m_balls.end(), speedUp);
}
