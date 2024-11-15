#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>

class UI {
public:
    UI();                                         // Hàm khởi tạo
    void displayScore(sf::RenderWindow &window, int score);  // Hiển thị điểm số
    void displayGameOver(sf::RenderWindow &window);          // Hiển thị "Game Over"
    sf::Font& getFont();                          // Trả về font chữ (để sử dụng trong Game)

private:
    sf::Font font;                                // Font chữ dùng cho văn bản
    sf::Text scoreText;                           // Văn bản hiển thị điểm số
    sf::Text gameOverText;                        // Văn bản hiển thị "Game Over"
};

#endif // UI_H
