#pragma once
#include <SFML\Graphics.hpp>
#include "Collision.h"

//	Forward Declarations
class Ball;
class Brick;
class Paddle;
class Bound;

class Drawable
{
public:
	Drawable();
	Drawable(int score);
	virtual ~Drawable();
	virtual void draw(sf::RenderWindow & win) = 0;
	virtual bool contains(const sf::Vector2f & point) const = 0;
	sf::FloatRect& bounds() const;
	int getVal()const;///

	//virtual Collision collide(const Drawable & obj) const = 0;
	//virtual Collision collide(const Ball & obj) const = 0;
	//virtual Collision collide(const Brick & obj) const = 0;
	//virtual Collision collide(const Paddle & obj) const = 0;
	//virtual Collision collide(const Bound & obj) const = 0;
protected:
	sf::Sprite m_sprite;
private:
	size_t m_value=0;///
};

