#pragma once

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>

class Game;

class BaseEntity
{
protected:
	Game* game;

public:
	BaseEntity(Game* game);

	virtual void update(sf::Time deltaTime) = 0;
	virtual void render() = 0;

	virtual void setPosition(const glm::vec2 position);
	virtual void setPosition(const float x, const float y) = 0;
	virtual glm::vec2 getPosition() const = 0;
};

