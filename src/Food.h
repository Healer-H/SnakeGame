#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>

class Food {
public:
    Food();
    void spawn(const sf::Vector2u &windowSize);  // Sinh thức ăn ngẫu nhiên trong phạm vi cửa sổ
    void draw(sf::RenderWindow &window);         // Vẽ thức ăn lên cửa sổ
    sf::Vector2f getPosition() const;            // Lấy vị trí hiện tại của thức ăn

private:
    sf::CircleShape foodShape;
};

#endif
