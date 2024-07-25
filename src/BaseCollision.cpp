#include "../include/BaseCollision.hpp"

void BaseCollision::calculateCollision(std::shared_ptr<BaseCollision> entity)
{
	if (getBounds().intersects(entity->getBounds()))
	{
		onCollision(entity);
	}
}
