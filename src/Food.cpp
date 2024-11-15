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

void Food::spawn(const sf::Vector2u& windowSize) {
    // Sinh vị trí ngẫu nhiên cho thức ăn
    int x = (std::rand() % windowSize.x);
    int y = (std::rand() % windowSize.y);
    shape.setPosition(static_cast<float>(x), static_cast<float>(y));
}

void Food::draw(sf::RenderWindow& window) const {
    window.draw(foodShape);
}