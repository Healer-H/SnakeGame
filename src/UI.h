#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>

class UI {
public:
    UI();
    void displayScore(sf::RenderWindow &window, int score);   // Hiển thị điểm số
    void displayGameOver(sf::RenderWindow &window);           // Hiển thị thông báo kết thúc game

private:
    sf::Font font;
    sf::Text scoreText;
    sf::Text gameOverText;
};

#endif
