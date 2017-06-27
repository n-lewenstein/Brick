#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation();
	Animation(int frmWd, int frmHt, int txtrWd, int txtrHt, const sf::Time& time = {});
	virtual ~Animation();
	void start();
	void stop();
	void step();
	void setRepeat(bool repeat);
	bool finished() const;
protected:
	const sf::IntRect& nextFrame();
private:
	std::vector<sf::IntRect> m_frames;
	sf::Clock m_clock;
	sf::Time m_delay;
	size_t m_curFrame;
	bool m_running;
	bool m_repeat;
};

