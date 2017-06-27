#include "TwoBalls.h"
#include "Board.h"


TwoBalls::TwoBalls(const sf::Vector2f & pos)
	:
	FallingObject(pos)
{
	if (textures::tbl_txtr.getNativeHandle() == 0)
		textures::tbl_txtr.loadFromFile(paths::fo_tbl_path);

	Drawable::m_sprite.setTexture(textures::tbl_txtr);
}

TwoBalls::~TwoBalls()
{}

void TwoBalls::action(Board & brd)
{
	sf::FloatRect bounds = brd.m_balls[0].bounds();
	sf::Vector2f centerPos = { bounds.left + bounds.width / 2, bounds.top + bounds.height / 2 };
	Ball bl(centerPos, bounds.width / 2);

	bl.setDirection(30);
	bl.setSpeed(brd.m_balls[0].getSpeed());

	brd.m_balls.push_back(bl);
}
