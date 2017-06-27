#pragma once
#include "Direction.h"

struct Collision
{
	bool collide;
	int relativeHit;
	HV orient;
	Direction<float> hittingObjDir;
};