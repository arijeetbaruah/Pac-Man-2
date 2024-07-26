#include "../include/Player.hpp"
#include "../include/Game.hpp"
#include "../include/loadFromResource.hpp"
#include "../include/GameStateMachine.hpp"
#include "../include/Map.hpp"
#include "../include/GameGameState.hpp"
#include "../assets/resource.h"

#include <spdlog/spdlog.h>

const float PLAYER_ANIMATION_SPEED = 1;

Player::Player(Game* game): BaseEntity(game), direction(EDirection::LEFT), animationIndex(0), animationTimer(PLAYER_ANIMATION_SPEED), gameGameState(0)
{
	texture = LoadFromResource::loadTextureFromResource(std::to_string(IDB_PNG1));
	sprite.setTexture(texture);
	InitializeAnimation();
	InitializeMovementDirection();
	sprite.setTextureRect(animations[direction][animationIndex]);
	sprite.setOrigin(sf::Vector2f(25, 25));

	glm::vec2 pos = glm::normalize(movementDirection[direction]) * 50.f + getPosition();
	movementHitBox = sf::RectangleShape(sf::Vector2f(50, 50));
	movementHitBox.setPosition(pos.x, pos.y);
}

void Player::InitializeAnimation()
{
	std::vector<sf::IntRect> rightAnimations;
	rightAnimations.push_back(sf::IntRect(50 * 17, 50 * 0, 50, 50));
	rightAnimations.push_back(sf::IntRect(50 * 17, 50 * 1, 50, 50));
	rightAnimations.push_back(sf::IntRect(50 * 17, 50 * 2, 50, 50));
	rightAnimations.push_back(sf::IntRect(50 * 17, 50 * 1, 50, 50));
	animations[EDirection::RIGHT] = rightAnimations;

	std::vector<sf::IntRect> leftAnimations;
	leftAnimations.push_back(sf::IntRect(50 * 17, 50 * 6, 50, 50));
	leftAnimations.push_back(sf::IntRect(50 * 17, 50 * 7, 50, 50));
	leftAnimations.push_back(sf::IntRect(50 * 17, 50 * 8, 50, 50));
	leftAnimations.push_back(sf::IntRect(50 * 17, 50 * 7, 50, 50));
	animations[EDirection::LEFT] = leftAnimations;

	std::vector<sf::IntRect> upAnimations;
	upAnimations.push_back(sf::IntRect(50 * 17, 50 * 9, 50, 50));
	upAnimations.push_back(sf::IntRect(50 * 17, 50 * 10, 50, 50));
	upAnimations.push_back(sf::IntRect(50 * 17, 50 * 11, 50, 50));
	upAnimations.push_back(sf::IntRect(50 * 17, 50 * 10, 50, 50));
	animations[EDirection::DOWN] = upAnimations;

	std::vector<sf::IntRect> downAnimations;
	downAnimations.push_back(sf::IntRect(50 * 17, 50 * 3, 50, 50));
	downAnimations.push_back(sf::IntRect(50 * 17, 50 * 4, 50, 50));
	downAnimations.push_back(sf::IntRect(50 * 17, 50 * 5, 50, 50));
	downAnimations.push_back(sf::IntRect(50 * 17, 50 * 4, 50, 50));
	animations[EDirection::UP] = downAnimations;
}

void Player::handleInput(sf::Event event)
{
}

void Player::InitializeMovementDirection()
{
	movementDirection[EDirection::UP] = glm::vec2(0, -0.5f);
	movementDirection[EDirection::DOWN] = glm::vec2(0, 0.5f);
	movementDirection[EDirection::RIGHT] = glm::vec2(0.5f, 0);
	movementDirection[EDirection::LEFT] = glm::vec2(-0.5f, 0);
}

void Player::update(sf::Time deltaTime)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		direction = EDirection::LEFT;
		glm::vec2 pos = (glm::normalize(movementDirection[direction]) * 50.f) + getPosition();
		movementHitBox.setPosition(pos.x, pos.y);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		direction = EDirection::RIGHT;
		glm::vec2 pos = glm::normalize(movementDirection[direction]) + getPosition();
		movementHitBox.setPosition(pos.x, pos.y);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		direction = EDirection::UP;
		glm::vec2 pos = glm::normalize(movementDirection[direction]) * 50.f + getPosition();
		movementHitBox.setPosition(pos.x, pos.y);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		direction = EDirection::DOWN;
		glm::vec2 pos = glm::normalize(movementDirection[direction]) + getPosition();
		movementHitBox.setPosition(pos.x, pos.y);
	}

	animationTimer -= deltaTime.asSeconds();
	if (animationTimer <= 0)
	{
		animationIndex++;
		if (animationIndex == animations[direction].size())
		{
			animationIndex = 0;
		}

		sprite.setTextureRect(animations[direction][animationIndex]);
		animationTimer = PLAYER_ANIMATION_SPEED;
	}

	if (gameGameState == nullptr)
	{
		gameGameState = std::dynamic_pointer_cast<GameGameState>(game->getGameStateMachine()->getCurrentState());
	}

	sf::Vector2f pos = movementHitBox.getPosition();
	std::shared_ptr<MapNode> mapNode = gameGameState->getMap()->getNodeFromPosition(glm::vec2(pos.x, pos.y));
	if (!mapNode->isWall) {
		move(movementDirection[direction]);
	}
	
	spdlog::info("is Wall = {}", mapNode->isWall);
}

void Player::render()
{
	game->window.draw(movementHitBox);
	game->window.draw(sprite);
}

void Player::setPosition(const float x, const float y)
{
	sprite.setPosition(x, y);

	glm::vec2 pos = (glm::normalize(movementDirection[direction]) * 50.f) + glm::vec2(x, y);
	movementHitBox = sf::RectangleShape(sf::Vector2f(50, 50));
	movementHitBox.setPosition(pos.x, pos.y);
}

glm::vec2 Player::getPosition() const
{
	sf::Vector2f position = sprite.getPosition();
	return glm::vec2(position.x, position.y);
}

void Player::setPosition(const glm::vec2 pos)
{
	BaseEntity::setPosition(pos);
}

void Player::move(const glm::vec2 position)
{
	sprite.move(sf::Vector2f(position.x, position.y));
	movementHitBox.move(sf::Vector2f(position.x, position.y));
}

void Player::onCollision(std::shared_ptr<BaseCollision> other)
{
}

sf::FloatRect Player::getBounds()
{
	return sprite.getGlobalBounds();
}
