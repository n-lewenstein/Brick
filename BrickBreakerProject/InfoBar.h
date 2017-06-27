#pragma once
#include "GameObject.h"
#include "Constants.h"
#include <SFML\Graphics.hpp>
#include <sstream>

class InfoBar :
	public Drawable
{
public:
	InfoBar();
	~InfoBar();
	virtual void draw(sf::RenderWindow & win) override;
	virtual bool contains(const sf::Vector2f & point) const override;
	void rstTime();
	void setBrickAmount(const int & amnt);
	void setLife();
	void addScore(const int & scr);
	
private:
	size_t m_score;
	size_t m_lifes;
	int m_amntBricks;
	sf::Clock m_time;
	sf::Time m_shwTime;
	sf::Text m_text;
	std::stringstream ss;
	

};

