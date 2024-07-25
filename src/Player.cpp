#include "../include/Player.hpp"
#include "../include/Game.hpp"

Player::Player(Game* game): BaseEntity(game)
{
	circle.setRadius(10);
}

void Player::update(sf::Time deltaTime)
{
}

void Player::render()
{
	game->window.draw(circle);
}

void Player::setPosition(const float x, const float y)
{
	circle.setPosition(x, y);
}

glm::vec2 Player::getPosition() const
{
	sf::Vector2f position = circle.getPosition();
	return glm::vec2(position.x, position.y);
}

void Player::onCollision(std::shared_ptr<BaseCollision> other)
{
}

sf::FloatRect Player::getBounds()
{
	return circle.getGlobalBounds();
}
