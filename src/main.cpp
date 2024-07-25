#include "../include/Game.hpp"

int main()
{
    Game* game = new Game(glm::vec2(1920u, 1080u), "Pac-Man");
    game->run();

    delete game;
}
