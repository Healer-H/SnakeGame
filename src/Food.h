#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>

class Food {
public:
    Food();
    void spawn(const sf::Vector2u& windowSize);
    sf::Vector2f getPosition() const;
    void draw(sf::RenderWindow& window) const;

private:
    sf::RectangleShape foodShape;
};

#endif // FOOD_H