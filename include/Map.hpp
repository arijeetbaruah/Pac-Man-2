#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <memory>
#include <map>

#include <glm/glm.hpp>

#include "./EDirection.hpp"

class Game;

class MapNode
{
private:
	Game* game;
	sf::RectangleShape sprite;
	glm::vec2 position;

public:
	MapNode(Game* game, glm::vec2 position, bool isWall);
	bool isWall;

	std::map<EDirection, std::shared_ptr<MapNode>> neighbour;

	void render();
};

class Map
{
private:
	std::vector<std::string> map;
	std::vector<std::vector<std::shared_ptr<MapNode>>> grid;

	glm::vec2 playerPos;

	Game* game;
public:
	Map(Game* game);
	void load(const std::string& filename);
	void render();

	glm::vec2 getPlayerPosition() const;
	std::shared_ptr<MapNode> getNodeFromPosition(glm::vec2 pos);
};

