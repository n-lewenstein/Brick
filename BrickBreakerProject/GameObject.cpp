#include "GameObject.h"

Drawable::Drawable()
{}

Drawable::Drawable(int score)
	:
	m_value(score)
{}

Drawable::~Drawable()
{}

sf::FloatRect & Drawable::bounds() const
{
	return m_sprite.getGlobalBounds();
}

int Drawable::getVal()const
{
	return m_value;
}
