#pragma once

#include "./BaseEntity.hpp"
#include "./BaseCollision.hpp"

class Player : public BaseEntity, public BaseCollision
{
private:
	sf::CircleShape circle;

public:
	Player(Game* game);

	// Inherited via BaseEntity
	void update(sf::Time deltaTime) override;
	void render() override;
	void setPosition(const float x, const float y) override;
	glm::vec2 getPosition() const override;

	// Inherited via BaseCollision
	void onCollision(std::shared_ptr<BaseCollision> other) override;
	sf::FloatRect getBounds() override;
};

