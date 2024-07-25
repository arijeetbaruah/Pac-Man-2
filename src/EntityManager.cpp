#include "../include/EntityManager.hpp"
#include "../include/BaseEntity.hpp"
#include "../include/BaseCollision.hpp"

EntityManager::EntityManager()
{
}

void EntityManager::AddEntity(std::shared_ptr<BaseEntity> entity)
{
	registry.push_back(entity);
}

void EntityManager::handleInput(sf::Event event)
{
	for (size_t index = 0; index < registry.size(); index++) {
		registry[index]->handleInput(event);
	}
}

void EntityManager::update(sf::Time deltaTime)
{
	for (size_t x = 0; x < registry.size(); x++) {
		std::shared_ptr<BaseCollision> collision1 = std::dynamic_pointer_cast<BaseCollision>(registry[x]);
		if (collision1 == NULL) {
			continue;
		}

		for (size_t y = x + 1; y < registry.size(); y++) {
			std::shared_ptr<BaseCollision> collision2 = std::dynamic_pointer_cast<BaseCollision>(registry[y]);
			if (collision2 != NULL) {
				collision1->calculateCollision(collision2);
			}
		}
	}

	for (size_t index = 0; index < registry.size(); index++) {
		registry[index]->update(deltaTime);
	}
}

void EntityManager::render()
{
	for (size_t index = 0; index < registry.size(); index++) {
		registry[index]->render();
	}
}
