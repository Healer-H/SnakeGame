#include "Food.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>  
#include <iostream>

Food::Food() {
    // Khởi tạo shape food
    shape.setSize(sf::Vector2f(40, 40));
    shape.setFillColor(sf::Color::Red);
}

void Food::spawn(const sf::FloatRect& playArea) {
    // Sinh vị trí ngẫu nhiên cho thức ăn, căn chỉnh theo lưới trong PlayArea
    int x = (rand() % static_cast<int>(playArea.width / 40)) * 40;
    int y = (rand() % static_cast<int>(playArea.height / 40)) * 40;

    int _top = (static_cast<int>(playArea.top) + 40) / 40 * 40;
    int _left = static_cast<int>(playArea.left) / 40 * 40;
    int _width = static_cast<int>(playArea.width) / 40 * 40;
    int _height = static_cast<int>(playArea.height) / 40 * 40;

    if (y < _top) {
        y = _top;
    }
    if(y > _height) {
        y = _height;
    }
    if (x < _left) {
        x = _left;
    }
    if (x > _width) {
        x = _width;
    }

    std::cout << "Food position: " << x << ", " << y << std::endl;
    shape.setPosition(static_cast<float>(x), static_cast<float>(y));
}


sf::Vector2f Food::getPosition() const {
    return shape.getPosition();
}

void Food::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}