#include "Food.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

Food::Food() {
    // Initialize the food's shape
    shape.setSize(sf::Vector2f(10, 10));
    shape.setFillColor(sf::Color::Red);
    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Food::spawn(const sf::FloatRect& playArea) {
    // Generate a random position aligned with the grid within PlayArea
    int x = static_cast<int>(playArea.left + (std::rand() % static_cast<int>(playArea.width / 10)) * 10);
    int y = static_cast<int>(playArea.top + (std::rand() % static_cast<int>(playArea.height / 10)) * 10);
    shape.setPosition(static_cast<float>(x), static_cast<float>(y));
}

sf::Vector2f Food::getPosition() const {
    return shape.getPosition();
}

void Food::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}
