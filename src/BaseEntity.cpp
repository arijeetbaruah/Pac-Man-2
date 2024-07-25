#include "../include/BaseEntity.hpp"

BaseEntity::BaseEntity(Game* game): game(game)
{
}

void BaseEntity::setPosition(const glm::vec2 position)
{
	setPosition(position.x, position.y);
}
