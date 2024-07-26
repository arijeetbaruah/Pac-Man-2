#pragma once

#include <string>
#include <vector>
#include <memory>
#include <map>

#include "./EDirection.hpp"

class Game;

class MapNode
{
private:
	Game* game;
public:
	MapNode(Game* game, bool isWall);
	bool isWall;

	std::map<EDirection, std::shared_ptr<MapNode>> neighbour;
};

class Map
{
private:
	std::vector<std::string> map;
	std::vector<std::vector<std::shared_ptr<MapNode>>> grid;

	Game* game;
public:
	Map(Game* game);
	void load(const std::string& filename);
};

