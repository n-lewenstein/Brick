#pragma once
#include "Board.h"

class Controller
{
public:
	Controller();
	~Controller();
	void runGame();
	void handleEvents(sf::RenderWindow & win);
private:
	Board m_board;
};

