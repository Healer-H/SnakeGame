#include "Food.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>  // For rand() and srand()
#include <iostream>

Food::Food() {
    // Initialize the food's shape
    shape.setSize(sf::Vector2f(40, 40));
    shape.setFillColor(sf::Color::Red);
}

void Food::spawn(const sf::FloatRect& playArea) {
    // Generate a random position aligned with the grid within PlayArea
    int x = static_cast<int>(playArea.left + (std::rand() % static_cast<int>(playArea.width / 40)) * 40);
    int y = static_cast<int>(playArea.top + (std::rand() % static_cast<int>(playArea.height / 40)) * 40);
    std::cout << "Food position: " << x << ", " << y << std::endl;
    shape.setPosition(static_cast<float>(x), static_cast<float>(y));
}

sf::Vector2f Food::getPosition() const {
    return shape.getPosition();
}

void Food::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}
