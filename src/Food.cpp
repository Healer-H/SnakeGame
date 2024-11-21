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

void Food::spawn(const sf::FloatRect& playArea) {
    // Sinh vị trí ngẫu nhiên cho thức ăn, căn chỉnh theo lưới trong PlayArea
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