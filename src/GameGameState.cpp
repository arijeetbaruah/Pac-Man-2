#include "../include/GameGameState.hpp"
#include "../include/EntityManager.hpp"
#include "../include/Player.hpp"
#include "../include/Game.hpp"
#include "../include/Map.hpp"

GameGameState::GameGameState(Game* game): BaseState(game)
{
	player = std::make_shared<Player>(game);
	game->getEntityManager()->AddEntity(player);
	
	map = std::make_shared<Map>(game);
	map->load("../map/map.txt");
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
