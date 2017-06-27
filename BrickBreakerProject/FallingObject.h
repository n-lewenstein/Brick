#pragma once
#include "GameObject.h"
#include "Movable.h"
#include "Animation.h"
#include "Collision.h"
#include "Paddle.h"
#include "Bound.h"

class Board;

class FallingObject :
	public Movable<UD>, public Animation
{
public:
	FallingObject();
	FallingObject(const sf::Vector2f & pos);
	virtual ~FallingObject();
	virtual void draw(sf::RenderWindow & win) override;
	virtual bool contains(const sf::Vector2f & point) const override;
	virtual void move() override;
	virtual void action(Board & brd) = 0;
	virtual Collision collide(const Paddle & pad);
	virtual Collision collide(const Bound & bnd);
};

enum Fallings : int
{
	ExpandPadType = 0,
	ShortenPadType,
	RapidBallType,
	SlowBallType,
	TwoBallsType,
	_num_of_fallings
};