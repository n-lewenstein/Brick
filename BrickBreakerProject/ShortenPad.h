#pragma once
#include "FallingObject.h"


class ShortenPad :
	public FallingObject
{
public:
	ShortenPad(const sf::Vector2f & pos);
	virtual ~ShortenPad();
	virtual void action(Board & brd) override;
};

