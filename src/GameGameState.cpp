#include "../include/GameGameState.hpp"
#include "../include/EntityManager.hpp"
#include "../include/Player.hpp"
#include "../include/Game.hpp"
#include "../include/loadFromResource.hpp"
#include "../assets/resource.h"

GameGameState::GameGameState(Game* game): BaseState(game)
{
	player = std::make_shared<Player>(game);
	game->getEntityManager()->AddEntity(player);

	std::string map = LoadFromResource::loadTxtFromResource(std::to_string(IDR_TXT1));
}

void GameGameState::onEntry()
{
}

void GameGameState::handleInput(sf::Event event)
{
}

void GameGameState::onUpdate(sf::Time deltaTime)
{
	player->move(glm::vec2(0, 5) * deltaTime.asSeconds());
}

void GameGameState::render()
{
}

void GameGameState::onExit()
{
}
