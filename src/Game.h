#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Food.h"
#include "UI.h"

class Game {
public:
    Game();
    void run();  // Chạy vòng lặp chính của trò chơi

private:
    sf::RenderWindow window;
    Snake snake;
    Food food;
    UI ui;

    // Các trạng thái của trò chơi
    enum class GameState { StartScreen, Playing, EndScreen };
    GameState currentState;

    int score;

    // Nút giao diện
    sf::RectangleShape startButton;  // Nút "Start"
    sf::RectangleShape replayButton; // Nút "Replay"

    void processInput();  // Xử lý đầu vào của người chơi
    void update();        // Cập nhật trạng thái trò chơi
    void render();        // Vẽ các thành phần lên cửa sổ

    // Các hàm vẽ màn hình giao diện
    void renderStartScreen();  // Hiển thị màn hình Start
    void renderEndScreen();    // Hiển thị màn hình End
};

#endif // GAME_H