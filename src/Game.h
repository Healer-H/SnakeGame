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

    bool canAcceptInput; 
    std::chrono::milliseconds inputDelay; 
    std::chrono::time_point<std::chrono::steady_clock> lastInputTime; 
};

#endif // GAME_H