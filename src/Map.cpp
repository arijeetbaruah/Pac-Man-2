#include "../include/Map.hpp"

#include <fstream>
#include <vector>
#include <iostream>

#include <spdlog/spdlog.h>

#include "../include/Game.hpp"

Map::Map(Game* game): game(game), playerPos(0, 0)
{
}

glm::vec2 Map::getPlayerPosition() const
{
    return playerPos;
}

void Map::render()
{
    for (size_t y = 0; y < grid.size(); y++) {
        for (size_t x = 0; x < grid[y].size(); x++) {
            grid[y][x]->render();
        }
    }
}

void Map::load(const std::string& filename)
{
	std::ifstream file(filename);
    std::string line;
    map.clear();

    while (std::getline(file, line)) {
        map.push_back(line);
    }

    for (size_t y = 0; y < map.size(); y++) {
        std::vector<std::shared_ptr<MapNode>> mapRow;

        for (size_t x = 0; x < map[y].length(); ++x) {
            std::shared_ptr<MapNode> mapNode = std::make_shared<MapNode>(game, glm::vec2(x,y), map[y][x] == '#');
            mapRow.push_back(mapNode);

            if (map[y][x] == 'P')
            {
                playerPos = glm::vec2(x * 50, y * 50);
            }
        }

        grid.push_back(mapRow);
    }

    for (size_t y = 0; y < grid.size(); y++) {
        for (size_t x = 0; x < grid[y].size(); x++) {
            if (y > 0) {
                grid[y - 1][x]->neighbour[EDirection::LEFT] = grid[y][x];
                grid[y][x]->neighbour[EDirection::RIGHT] = grid[y - 1][x];
            }

            if (x > 0) {
                grid[y][x - 1]->neighbour[EDirection::DOWN] = grid[y][x];
                grid[y][x]->neighbour[EDirection::UP] = grid[y][x - 1];
            }
        }
    }
}

std::shared_ptr<MapNode> Map::getNodeFromPosition(glm::vec2 pos)
{
    return grid[(int) pos.y / 50][(int) pos.x / 50];
}

MapNode::MapNode(Game* game, glm::vec2 position, bool isWall): game(game), isWall(isWall), position(position)
{
    neighbour[EDirection::UP] = NULL;
    neighbour[EDirection::DOWN] = NULL;
    neighbour[EDirection::LEFT] = NULL;
    neighbour[EDirection::RIGHT] = NULL;

    sprite = sf::RectangleShape(sf::Vector2f(50, 50));
    sprite.setPosition(position.x * 50, position.y * 50);
    sprite.setOrigin(25, 25);
}

void MapNode::render()
{
    if (isWall)
    {
        game->window.draw(sprite);
    }
}
