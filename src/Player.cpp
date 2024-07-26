#include "../include/Player.hpp"
#include "../include/Game.hpp"
#include "../assets/resource.h"
#include "../include/loadFromResource.hpp"

const float PLAYER_ANIMATION_SPEED = 1;

Player::Player(Game* game): BaseEntity(game), direction(EDirection::LEFT), animationIndex(0), animationTimer(PLAYER_ANIMATION_SPEED)
{
	texture = LoadFromResource::loadTextureFromResource(std::to_string(IDB_PNG1));
	sprite.setTexture(texture);
	InitializeAnimation();
	sprite.setTextureRect(animations[direction][animationIndex]);
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
	animations[EDirection::UP] = upAnimations;

	std::vector<sf::IntRect> downAnimations;
	downAnimations.push_back(sf::IntRect(50 * 17, 50 * 3, 50, 50));
	downAnimations.push_back(sf::IntRect(50 * 17, 50 * 4, 50, 50));
	downAnimations.push_back(sf::IntRect(50 * 17, 50 * 5, 50, 50));
	downAnimations.push_back(sf::IntRect(50 * 17, 50 * 4, 50, 50));
	animations[EDirection::DOWN] = downAnimations;
}

void Player::handleInput(sf::Event event)
{
}

void Player::update(sf::Time deltaTime)
{
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
}

void Player::render()
{
	game->window.draw(sprite);
}

void Player::setPosition(const float x, const float y)
{
	sprite.setPosition(x, y);
}

glm::vec2 Player::getPosition() const
{
	sf::Vector2f position = sprite.getPosition();
	return glm::vec2(position.x, position.y);
}

void Player::move(const glm::vec2 position)
{
	sprite.move(sf::Vector2f(position.x, position.y));
}

void Player::onCollision(std::shared_ptr<BaseCollision> other)
{
}

sf::FloatRect Player::getBounds()
{
	return sprite.getGlobalBounds();
}
