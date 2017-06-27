#pragma once
#include <vector>
#include <memory>
#include <fstream>
#include "GameObject.h"
#include "LevelObject.h"
#include "Brick.h"
#include "Ball.h"
#include "Paddle.h"

class Level
{
public:
	Level();
	Level(std::ifstream & file);
	virtual ~Level();
	virtual void draw(sf::RenderWindow & win);
private:
};

