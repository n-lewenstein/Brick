#pragma once
#include "FallingObject.h"

class ExpandPad :
	public FallingObject
{
public:
	ExpandPad(const sf::Vector2f & pos);
	virtual ~ExpandPad();
	virtual void action(Board & brd) override;
};

