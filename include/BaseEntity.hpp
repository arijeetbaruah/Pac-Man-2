#pragma once

#include <SFML/Graphics.hpp>

class Game;

class BaseEntity : public sf::Transformable
{
protected:
	Game* game;

public:
	BaseEntity(Game* game);

	virtual void update(sf::Time deltaTime) = 0;
	virtual void render() = 0;
};

