#pragma once
#include "Direction.h"
#include "Collision.h"

class AngCalc
{
public:
	AngCalc();
	~AngCalc();
	virtual Direction<float> calc(const Collision & collision) = 0;
};

