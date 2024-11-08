#pragma once

#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <deque>

class Snake : public sf::Drawable {
public: 
    // Constructor và Destructor
    Snake();
    ~Snake();

     // Khởi tạo con rắn với một texture
    void Init(const sf::Texture &texture);

    // Di chuyển con rắn theo hướng chỉ định
    void Move(const sf::Vector2f &direction);

    // Kiểm tra xem đầu con rắn có nằm trên sprite khác không
    bool IsOn(const sf::Sprite &other) const;

    // Làm con rắn dài hơn theo hướng chỉ định
    void Grow(const sf::Vector2f &direction);

    // Kiểm tra xem con rắn có tự va vào chính nó không
    bool IsSelfIntersecting() const;

    // Ghi đè hàm draw để vẽ con rắn
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    // void move();                   // Di chuyển rắn
    // void grow();                   // Tăng chiều dài rắn khi ăn thức ăn
    // void draw(sf::RenderWindow &window);  // Vẽ rắn lên cửa sổ
    // bool checkCollision();         // Kiểm tra va chạm với chính thân mình hoặc biên

private:
    std::list<sf::Sprite> m_body; // Danh sách các phần thân của rắn
    std::list<sf::Sprite>::iterator m_head; // Iterator trỏ đến đầu rắn
    std::list<sf::Sprite>::iterator m_tail; // Iterator trỏ đến đuôi rắn
    // std::deque<sf::Vector2f> body;  // Vị trí của các đoạn thân rắn
    // sf::Vector2f direction;         // Hướng di chuyển
};

#endif
