#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <deque>

class Snake {
public:
    Snake(const sf::Texture& headTexture, const sf::Texture& bodyTexture);          // Constructor  
    void move(const sf::FloatRect& playArea);                                       // Di chuyển rắn trong PlayArea 
    void setDirection(const sf::Vector2f& newDirection);                            // Đặt hướng di chuyển
    sf::Vector2f getHeadPosition() const;                                           // Lấy vị trí đầu rắn
    void grow();                                                                    // Tăng chiều dài rắn khi ăn thức ăn
    bool checkCollision(const sf::FloatRect& playArea) const;                       // Kiểm tra va chạm
    bool checkCollisionWithFood(const sf::Vector2f& foodPosition) const;            // Kiểm tra va chạm với thức ăn
    void draw(sf::RenderWindow &window) const;                                            // Vẽ rắn lên cửa sổ

private:
    std::vector<sf::RectangleShape> body;                                           // Các đoạn của rắn
    sf::Vector2f direction;                                                         // Hướng di chuyển của rắn
    const sf::Texture* bodyTexture;                                                 // Texture cho thân rắn
};

#endif // SNAKE_H