#include "ExpandPad.h"
#include "Board.h"

ExpandPad::ExpandPad(const sf::Vector2f & pos)
	:
	FallingObject(pos)
{
	if (textures::exp_txtr.getNativeHandle() == 0)
		textures::exp_txtr.loadFromFile(paths::fo_exp_path);

	Drawable::m_sprite.setTexture(textures::exp_txtr);
}

ExpandPad::~ExpandPad()
{}

void ExpandPad::action(Board & brd)
{
	brd.m_pad.expand(1.4f);
}
