#include "Controller.h"
#include "Constants.h"

Controller::Controller()
{
	srand(time(NULL));
}

Controller::~Controller()
{}

void Controller::runGame()
{
	sf::RenderWindow win(sf::VideoMode(sizes::win_wd, sizes::win_ht), "Brick-Breaker");
	win.setFramerateLimit(0);
	while (win.isOpen())
	{
		win.clear();

		handleEvents(win);
		
		m_board.boardEvents(win);
		m_board.update();
		m_board.moveAll();
		m_board.draw(win);

		win.display();
	}
}

void Controller::handleEvents(sf::RenderWindow & win)
{
	sf::Event myEvent;

	while (win.pollEvent(myEvent))
	{
		switch (myEvent.type)
		{
		case sf::Event::Closed:
			win.close();
		default:
			break;
		}
	}
}
