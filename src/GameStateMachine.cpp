#include "../include/GameStateMachine.hpp"
#include "../include/GameGameState.hpp"
#include "../include/BaseState.hpp"

GameStateMachine::GameStateMachine(Game* game)
{
	gameGameState = std::make_shared<GameGameState>(game);

	setState(gameGameState);
}

void GameStateMachine::setState(std::shared_ptr<BaseState> state)
{
	if (currentState != nullptr)
	{
		currentState->onExit();
	}

	currentState = state;
	currentState->onEntry();
}

void GameStateMachine::handleInput(sf::Event event)
{
	if (currentState != nullptr)
	{
		currentState->handleInput(event);
	}
}

void GameStateMachine::update(sf::Time deltaTime)
{
	if (currentState != nullptr)
	{
		currentState->onUpdate(deltaTime);
	}
}

void GameStateMachine::render()
{
	if (currentState != nullptr)
	{
		currentState->render();
	}
}

std::shared_ptr<BaseState> GameStateMachine::getCurrentState() const
{
	return currentState;
}
