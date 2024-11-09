#include "UI.h"
#include <string>

UI::UI() {
    // Thiết lập văn bản cho điểm số
    // scoreText.setFont(font);
    scoreText.setCharacterSize(24);                 // Kích thước chữ
    scoreText.setFillColor(sf::Color::White);       // Màu trắng cho chữ
    scoreText.setPosition(10, 10);                  // Vị trí ở góc trên bên trái

    // Thiết lập văn bản cho "Game Over"
    // gameOverText.setFont(font);
    gameOverText.setString("Game Over!");
    gameOverText.setCharacterSize(48);              // Kích thước chữ lớn hơn cho Game Over
    gameOverText.setFillColor(sf::Color::Red);      // Màu đỏ cho chữ
    gameOverText.setPosition(200, 250);             // Vị trí trung tâm màn hình (có thể thay đổi)
}

void UI::displayScore(sf::RenderWindow &window, int score) {
    // Cập nhật điểm số và hiển thị trên màn hình
    scoreText.setString("Score: " + std::to_string(score));
    window.draw(scoreText);
}

void UI::displayGameOver(sf::RenderWindow &window) {
    // Hiển thị thông báo "Game Over"
    window.draw(gameOverText);
}