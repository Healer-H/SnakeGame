#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp> // Đảm bảo khai báo đúng FloatRect

class Food {
public:
    Food();
    void spawn(const sf::FloatRect& playArea); // Sinh thức ăn trong PlayArea
    sf::Vector2f getPosition() const;
    void draw(sf::RenderWindow& window) const;

private:
    sf::RectangleShape shape;
};

#endif // FOOD_H
