#pragma once

#include "./BaseEntity.hpp"
#include "./BaseCollision.hpp"
#include "./EDirection.hpp"

class GameGameState;

class Player : public BaseEntity, public BaseCollision
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	sf::RectangleShape movementHitBox;

	std::map<EDirection, std::vector<sf::IntRect>> animations;
	std::map<EDirection, glm::vec2> movementDirection;
	EDirection direction;
	size_t animationIndex;
	float animationTimer;

	std::shared_ptr<GameGameState> gameGameState;

	void InitializeAnimation();
	void InitializeMovementDirection();

public:
	Player(Game* game);

	// Inherited via BaseEntity
	void handleInput(sf::Event event) override;
	void update(sf::Time deltaTime) override;
	void render() override;
	void setPosition(const float x, const float y) override;
	void setPosition(const glm::vec2) override;
	glm::vec2 getPosition() const override;
	void move(const glm::vec2 position) override;

	// Inherited via BaseCollision
	void onCollision(std::shared_ptr<BaseCollision> other) override;
	sf::FloatRect getBounds() override;

};

