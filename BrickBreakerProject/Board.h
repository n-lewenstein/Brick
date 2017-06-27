#pragma once
#include <list>
#include "InfoBar.h"
#include "Level.h"
#include "FallingObject.h"
#include "Bound.h"
#include "Paddle.h"
#include "Ball.h"

class Board
{
	friend class ExpandPad;
	friend class ShortenPad;
	friend class SlowBall;
	friend class RapidBall;
	friend class TwoBalls;
public:
	Board();
	~Board();
	void setLevel(const Level & level);
	void draw(sf::RenderWindow & win);
	void update();
	void moveAll();
	void boardEvents(sf::RenderWindow & win);
private:
	std::shared_ptr<FallingObject> randomFalling(const sf::Vector2f & pos) const;
	InfoBar m_info;
	Paddle	m_pad;
	Bound	m_bnd;
	std::vector<Ball> m_balls;
	std::list<Brick> m_bricks;
	std::vector<std::shared_ptr<FallingObject>> m_fall;
	sf::Sprite m_backgrnd;
};

