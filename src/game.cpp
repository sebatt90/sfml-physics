#include "game.h"

sf::Clock deltaClock;
sf::Clock timeClock;


float Game::getDelta(){
    return deltaClock.restart().asSeconds();
}