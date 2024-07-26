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

	glm::vec2 pos = map->getPlayerPosition();
	player->setPosition(pos);
}

std::shared_ptr<Map> GameGameState::getMap() const
{
	return map;
}

void GameGameState::onEntry()
{
}

void GameGameState::handleInput(sf::Event event)
{
}

void GameGameState::onUpdate(sf::Time deltaTime)
{
}

void GameGameState::render()
{
	map->render();
}

void GameGameState::onExit()
{
}
