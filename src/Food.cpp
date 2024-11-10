#include "Food.h"
#include <SFML/Graphics.hpp>

void Food::draw(sf::RenderWindow& window) const {
    window.draw(foodShape);
}