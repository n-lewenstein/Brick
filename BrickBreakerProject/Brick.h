#pragma once
#include "Animation.h"
#include "LevelObject.h"
#include "AngCalc.h"
#include "Collision.h"
#include "Constants.h"

class Brick :
	public Drawable, public Animation, public AngCalc
{
public:
	Brick(const sf::Vector2f & pos, int hits);
	virtual ~Brick();
	virtual void draw(sf::RenderWindow & win) override;
	virtual bool contains(const sf::Vector2f & point) const override;
	virtual Direction<float> calc(const Collision & collision) override;
	void hit();
	int hitsLeft() const;
private:
	int m_hitsLeft;
};

