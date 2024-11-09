#include "UI.h"
#include <string>

void UI::displayScore(sf::RenderWindow &window, int score) {
    // Cập nhật điểm số và hiển thị trên màn hình
    scoreText.setString("Score: " + std::to_string(score));
    window.draw(scoreText);
}

void UI::displayGameOver(sf::RenderWindow &window) {
    // Hiển thị thông báo "Game Over"
    window.draw(gameOverText);
}