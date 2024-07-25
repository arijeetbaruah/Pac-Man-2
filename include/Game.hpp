#pragma once

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>
#include <memory>

class EntityManager;
class GameStateMachine;

class Game
{
public:
	sf::RenderWindow window;

private:
	std::shared_ptr<EntityManager> entityManager;
	std::shared_ptr<GameStateMachine> gameStateMachine;

public:
	Game(glm::vec2 windowSize, std::string title);
	void run();

	std::shared_ptr<EntityManager> getEntityManager() const;
	std::shared_ptr<GameStateMachine> getGameStateMachine() const;
};
