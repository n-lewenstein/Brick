#pragma once
#include "FallingObject.h"

class TwoBalls :
	public FallingObject
{
public:
	TwoBalls(const sf::Vector2f & pos);
	virtual ~TwoBalls();
	virtual void action(Board & brd) override;
};

