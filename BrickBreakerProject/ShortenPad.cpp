#include "ShortenPad.h"
#include "Board.h"


ShortenPad::ShortenPad(const sf::Vector2f & pos)
	:
	FallingObject(pos)
{
	if (textures::srt_txtr.getNativeHandle() == 0)
		textures::srt_txtr.loadFromFile(paths::fo_srt_path);

	Drawable::m_sprite.setTexture(textures::srt_txtr);
}

ShortenPad::~ShortenPad()
{}

void ShortenPad::action(Board & brd)
{
	brd.m_pad.expand(1 / 1.4f);
}
