#include "Game.h"

void Snake::draw(sf::RenderWindow& window) const {
    for (const auto& segment : body) {
        window.draw(segment);
    }
}