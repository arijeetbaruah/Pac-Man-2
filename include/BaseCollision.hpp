#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class BaseCollision
{
public:
	virtual void onCollision(std::shared_ptr<BaseCollision> other) = 0;
	void calculateCollision(std::shared_ptr<BaseCollision> entity);

	virtual sf::FloatRect getBounds() = 0;
};
