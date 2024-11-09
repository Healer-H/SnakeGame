#include "Food.h"
#include <SFML/Graphics.hpp>
#include <cstdlib> // For rand() và srand()
#include <ctime>   // For time()

Food::Food()
{
    // Khởi tạo hình dạng của đồ ăn
    foodShape.setSize(sf::Vector2f(10, 10));
    foodShape.setFillColor(sf::Color::Red);
    // Sinh số ngẫu nhiên
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Food::spawn(const sf::Vector2u &windowSize)
{
    // Tạo vị trí ngẫu nhiên được căn chỉnh với lưới
    int x = (std::rand() % (windowSize.x));
    int y = (std::rand() % (windowSize.y));
    foodShape.setPosition(static_cast<float>(x), static_cast<float>(y));
}

void Food::draw(sf::RenderWindow& window) const {
    window.draw(foodShape);
}