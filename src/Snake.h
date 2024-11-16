#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <deque>

class Snake {
public:
    Snake();         
    void move(const sf::Vector2u& windowSize);                      // Di chuyển rắn     
    void grow();                                                    // Tăng chiều dài rắn khi ăn thức ăn
    void draw(sf::RenderWindow &window);                            // Vẽ rắn lên cửa sổ
    bool checkCollision(const sf::Vector2u& windowSize) const;      // Kiểm tra va chạm với chính thân mình hoặc biên


private:
    std::deque<sf::Vector2f> body;  // Vị trí của các đoạn thân rắn
    sf::Vector2f direction;         // Hướng di chuyển
};

#endif
