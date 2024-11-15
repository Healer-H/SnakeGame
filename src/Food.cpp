#include "Food.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>  
#include <ctime>

Food::Food() {
    // Khởi tạo shape food
    shape.setSize(sf::Vector2f(10, 10));
    shape.setFillColor(sf::Color::Red);
    // Seed để sinh ra số ngẫu nhiên
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Food::draw(sf::RenderWindow& window) const {
    window.draw(foodShape);
}