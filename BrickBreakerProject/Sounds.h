#pragma once
#include <SFML\Audio.hpp>
#include "Constants.h"


class Sounds
{
public:
	Sounds();
	static void playSound(const SoundType & soundType);
private:
	sf::SoundBuffer m_brk_hit_buf;
	static sf::Sound m_brk_hit;
};

