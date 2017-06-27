#pragma once
#include "FallingObject.h"

class SlowBall :
	public FallingObject
{
public:
	SlowBall(const sf::Vector2f & pos);
	virtual ~SlowBall();
	virtual void action(Board & brd) override;
};

