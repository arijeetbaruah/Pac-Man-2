#include "../include/Game.hpp"
#include "../include/EntityManager.hpp"

#include "../include/Player.hpp"

Game::Game(glm::vec2 windowSize, std::string title)
	: window(sf::RenderWindow{ sf::VideoMode(windowSize.x, windowSize.y), title, sf::Style::Default })
{
	window.setFramerateLimit(144);

    entityManager = std::make_shared<EntityManager>();
}

void Game::run()
{
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        entityManager->update(elapsed);

        window.clear();
        entityManager->render();
        window.display();
    }
}

std::shared_ptr<EntityManager> Game::getEntityManager() const
{
    return entityManager;
}
