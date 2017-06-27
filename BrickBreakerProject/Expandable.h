#pragma once
#include "GameObject.h"

class Expandable :
	public virtual Drawable
{
public:
	Expandable();
	~Expandable();
	virtual void expand(float mul) = 0;
};

