#include "Food.h"
#include <SFML/Graphics.hpp>


sf::Vector2f Food::getPosition() const {
    return shape.getPosition();
}

void Food::draw(sf::RenderWindow& window) const {
    window.draw(foodShape);
}