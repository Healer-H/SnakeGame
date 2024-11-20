#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Food.h"
#include "UI.h"

enum class GameState {
    Start,
    Run,
    End
};
class Game {
public:
    Game();
    void run();  // Chạy vòng lặp chính của trò chơi

private:
    sf::RenderWindow window;
    Snake snake;
    Food food;
    UI ui;

    int score;
    GameState gameState;

    void processInput();  // Xử lý đầu vào của người chơi
    void update();        // Cập nhật trạng thái trò chơi
    void render();        // Vẽ các thành phần lên cửa sổ
};

#endif
