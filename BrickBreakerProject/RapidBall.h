#pragma once
#include "FallingObject.h"
class RapidBall :
	public FallingObject
{
public:
	RapidBall(const sf::Vector2f & pos);
	virtual ~RapidBall();
	virtual void action(Board & brd) override;
};

