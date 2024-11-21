#include "Game.h"
#include "Snake.h"
#include <iostream>

// Constructor
Snake::Snake(const sf::Texture& headTexture, const sf::Texture& bodyTexture)
    : bodyTexture(&bodyTexture) {                                             // Gán texture thân rắn
    // Initialize the snake's head
    sf::RectangleShape head(sf::Vector2f(40, 40));                            // Set kích thước là 40x40
    head.setTexture(&headTexture); 
    head.setTextureRect(sf::IntRect(0, 0, headTexture.getSize().x, headTexture.getSize().y));
    
    head.setPosition(280, 160);                                               // Đặt vị trí đầu rắn
    body.push_back(head);

    // Initialize the first segment of the body
    sf::RectangleShape segment(sf::Vector2f(40, 40));
    segment.setTexture(&bodyTexture);
    segment.setTextureRect(sf::IntRect(0, 0, bodyTexture.getSize().x, bodyTexture.getSize().y));
    segment.setPosition(240, 160);                    // Đặt vị trí thân rắn
    body.push_back(segment);

    direction = sf::Vector2f(1, 0); // Initial direction: right
}

// Di chuyển rắn
void Snake::move(const sf::FloatRect& playArea) {
    // Move the snake's body
    for (int i = body.size() - 1; i > 0; --i) {
        body[i].setPosition(body[i - 1].getPosition());
    }
    body[0].move(direction * 40.0f); // Di chuyển theo khoảng cách 40px

    // Wrap around within PlayArea
    sf::Vector2f headPos = body[0].getPosition();
    int _left = (static_cast<int>(playArea.left) + 40 - 1) / 40 * 40;
    int _top = (static_cast<int>(playArea.top) + 40 - 1) / 40 * 40;
    int _width = static_cast<int>(playArea.width) / 40 * 40;
    int _height = static_cast<int>(playArea.height) / 40 * 40;
    if (headPos.x < _left) {
        headPos.x = _left + _width - 40;
    } else if (headPos.x >= _left + _width) {
        headPos.x = _left;
    }
    if (headPos.y < _top) {
        headPos.y = _top + _height - 40;
    } else if (headPos.y >= _top + _height) {
        headPos.y = _top;
    }
    body[0].setPosition(headPos);
}

// Đặt hướng di chuyển
void Snake::setDirection(const sf::Vector2f& newDirection) {
    if ((direction.x != -newDirection.x || direction.x == 0) &&
        (direction.y != -newDirection.y || direction.y == 0)) {
        direction = newDirection;
    }
}

// Lấy vị trí đầu rắn
sf::Vector2f Snake::getHeadPosition() const {
    return body[0].getPosition();
}

// Thêm một đoạn thân rắn
void Snake::grow() {
    // Thêm một đoạn thân mới vào vị trí của đoạn cuối cùng
    sf::RectangleShape newSegment(sf::Vector2f(40, 40));
    newSegment.setTexture(bodyTexture);                              // Đảm bảo texture không bị null && Sử dụng texture đã lưu
    newSegment.setTextureRect(sf::IntRect(0, 0, 40, 40));            // Gán vùng hiển thị đúng
    newSegment.setPosition(body.back().getPosition());               // Đặt vị trí đoạn mới
    body.push_back(newSegment);
}

// Kiểm tra va chạm
bool Snake::checkCollision(const sf::FloatRect& playArea) const {
    for (int i = 1; i < body.size(); ++i) {
        if (body[0].getPosition() == body[i].getPosition()) {
            return true;
        }
    }
    sf::Vector2f headPos = body[0].getPosition();
    if (headPos.x < playArea.left || headPos.x >= playArea.left + playArea.width ||
        headPos.y < playArea.top || headPos.y >= playArea.top + playArea.height) {
        return true;
    }
    return false;
}

// Kiểm tra va chạm với thức ăn
bool Snake::checkCollisionWithFood(const sf::Vector2f& foodPosition) const {
    for(size_t i = 0; i < body.size(); ++i) {
        if (body[i].getPosition() == foodPosition) {
            return true;
        }
    }
    return false;
}

void Snake::draw(sf::RenderWindow& window) const {
    for (const auto& segment : body) {
        window.draw(segment);
    }
}