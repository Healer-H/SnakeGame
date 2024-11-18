#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Food.h"
#include "UI.h"
#include <chrono>

enum class GameState {
    Start,
    Run,
    End
};

class Game {
public:
    Game();
    void run();

private:
    void processInput();
    void update();
    void render();

    sf::RenderWindow window;
    Snake snake;
    Food food;
    UI ui;
    int score;
    GameState gameState;

    bool canAcceptInput; // Biến cờ để kiểm soát input
    std::chrono::milliseconds inputDelay; // Thời gian chờ giữa các lần nhập input
    std::chrono::time_point<std::chrono::steady_clock> lastInputTime; // Thời gian nhập input cuối cùng
};

#endif // GAME_H