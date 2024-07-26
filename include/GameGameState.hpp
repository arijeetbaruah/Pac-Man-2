#pragma once

#include "./BaseState.hpp"
#include <memory>

class Player;
class Map;

class GameGameState : public BaseState
{
private:
	std::shared_ptr<Player> player;
	std::shared_ptr<Map> map;

public:
	GameGameState(Game* game);

	std::shared_ptr<Map> getMap() const;

	// Inherited via BaseState
	void onEntry() override;
	void handleInput(sf::Event event) override;
	void onUpdate(sf::Time deltaTime) override;
	void render() override;
	void onExit() override;
};
