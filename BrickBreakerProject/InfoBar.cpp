#include "InfoBar.h"
#include <iostream>



InfoBar::InfoBar()
{
	textures::ib_txtr.loadFromFile(paths::ib_path);
	Drawable::m_sprite.setTexture(textures::ib_txtr);
	Drawable::m_sprite.setPosition({(float) sizes::ib_x,(float) sizes::ib_y });

	m_score = 0;

	//Set Life
	m_lifes = m_lifes+1;

	//Font load
	fonts::ib_font.loadFromFile(paths::font_path);
	m_text.setFont(fonts::ib_font);
	m_text.setCharacterSize(sizes::font_size);
	m_text.setFillColor(sf::Color::Green);
	
}


InfoBar::~InfoBar()
{
}

void InfoBar::draw(sf::RenderWindow & win)
{
	//Background
	win.draw(Drawable::m_sprite);
	
	//Time
	//ss.str(std::string()); //clear the string
	//int seconds = m_time.getElapsedTime().asSeconds();
	//ss <<"TIME: " <<seconds;
	//m_text.setString(ss.str().c_str());
	//win.draw(m_text);

	//Life
	m_text.setPosition(50.0, 100.0);
	ss.str(std::string()); //clear the string
	ss << "Bricks: " << m_amntBricks;
	m_text.setString(ss.str().c_str());
	win.draw(m_text);

	//Score
	m_text.setPosition(400.0, 100.0);
	ss.str(std::string()); //clear the string
	ss << "Score: " << m_score;
	m_text.setString(ss.str().c_str());
	win.draw(m_text);


}

bool InfoBar::contains(const sf::Vector2f & point) const
{
	return Drawable::m_sprite.getGlobalBounds().contains(point);
}

void InfoBar::rstTime()
{
	m_time.restart();
}

void InfoBar::setBrickAmount(const int & amnt)
{
	m_amntBricks = amnt;
}

void InfoBar::addScore(const int & scr)
{
		m_score += scr;
}
