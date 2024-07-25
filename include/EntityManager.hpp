#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

class BaseEntity;

class EntityManager
{
private:
	std::vector<std::shared_ptr<BaseEntity>> registry;

public:
	EntityManager();

	void AddEntity(std::shared_ptr<BaseEntity> entity);

	void update(sf::Time deltaTime);
	void render();
};

