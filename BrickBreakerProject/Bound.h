#pragma once
#include "GameObject.h"
#include "AngCalc.h"
#include "Direction.h"
#include "Collision.h"

class Bound :
	public Drawable, public AngCalc
{
public:
	Bound();
	virtual ~Bound();
	virtual Direction<float> calc(const Collision & collision) override;
	virtual void draw(sf::RenderWindow & win) override;
	virtual bool contains(const sf::Vector2f & point) const;
private:
	sf::IntRect m_bounds;
};

