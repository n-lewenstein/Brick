#pragma once
#include <memory>
#include "Movable.h"
#include "Animation.h"
#include "Expandable.h"
#include "LevelObject.h"
#include "Collision.h"
#include "Paddle.h"
#include "Brick.h"
#include "Bound.h"

class Ball :
	public Movable<float>, public Animation, public Expandable
{
public:
	Ball();
	Ball(const sf::Vector2f & center, float radius);
	~Ball();
	virtual void draw(sf::RenderWindow & win) override;
	virtual bool contains(const sf::Vector2f & point) const override;
	virtual void move() override;
	virtual void expand(float mul) override;
	//virtual Collision collide(const Drawable & obj) const;
	//virtual Collision collide(const Ball & obj) const;
	//virtual Collision collide(const Brick & obj) const;
	//virtual Collision collide(const Paddle & obj) const;
	virtual Collision collide(const Bound & obj) const;
	virtual Collision collide(const Paddle & obj) const;
	virtual Collision collide(const Brick & obj) const;
	virtual Collision collide(const std::shared_ptr<Drawable> & obj) const;
private:
	sf::Vector2f m_center;
	float m_radius;
};

