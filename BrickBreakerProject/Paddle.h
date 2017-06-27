#pragma once
#include "Movable.h"
#include "Animation.h"
#include "Expandable.h"
#include "LevelObject.h"
#include "AngCalc.h"
#include "Collision.h"

class Paddle :
	public Movable<LR>, public Animation, public Expandable, public AngCalc
{
public:
	//using Movable<LR>::bounds;
	//using Expandable::bounds;
	Paddle();
	virtual ~Paddle();
	virtual void draw(sf::RenderWindow & win) override;
	virtual bool contains(const sf::Vector2f & point) const override;
	virtual void move() override;
	virtual void expand(float mul) override;
	virtual Direction<float> calc(const Collision & collision) override;
};
