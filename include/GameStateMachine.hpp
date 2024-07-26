#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class Game;
class BaseState;
class GameGameState;

class GameStateMachine
{
protected:
	std::shared_ptr<BaseState> currentState;

public:
	std::shared_ptr<GameGameState> gameGameState;
	
public:
	GameStateMachine(Game* game);

	void setState(std::shared_ptr<BaseState> state);
	void handleInput(sf::Event event);
	void update(sf::Time deltaTime);
	void render();

	std::shared_ptr<BaseState> getCurrentState() const;
};

