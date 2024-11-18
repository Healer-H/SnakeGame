#include "Game.h"
#include <iostream>
#include <thread>
#include <chrono>

Game::Game()
    : window(sf::VideoMode(800, 600), "SnakeGame"),
      score(0),
      gameState(GameState::Start),
      snake(ui.getSnakeHeadTexture(), ui.getSnakeBodyTexture()) {}  // Truyền texture

void Game::run() {
    while (window.isOpen()) {
        processInput();
        update();
        render();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Game::processInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (gameState == GameState::Start && ui.isButtonClicked(window, ui.getPlayButton())) {
            gameState = GameState::Run;
            snake = Snake(ui.getSnakeHeadTexture(), ui.getSnakeBodyTexture());
            food = Food();
            score = 0;
        } else if (gameState == GameState::End && ui.isButtonClicked(window, ui.getReplayButton())) {
            gameState = GameState::Start;
        }

        if (gameState == GameState::Run && event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Up: snake.setDirection({0, -1}); break;
                case sf::Keyboard::Down: snake.setDirection({0, 1}); break;
                case sf::Keyboard::Left: snake.setDirection({-1, 0}); break;
                case sf::Keyboard::Right: snake.setDirection({1, 0}); break;
                default: break;
            }
        }
    }
}

void Game::update() {
    if (gameState != GameState::Run) return;

    snake.move(ui.getPlayArea());

    if (snake.getHeadPosition() == food.getPosition()) {
        snake.grow();
        score += 10;
        food.spawn(ui.getPlayArea());
    }

    if (snake.checkCollision(ui.getPlayArea())) {
        gameState = GameState::End;
    }
}

void Game::render() {
    if (gameState == GameState::Start) {
        ui.displayStartScreen(window);
    } else if (gameState == GameState::Run) {
        window.clear();
        window.draw(ui.getBackgroundSprite()); // Vẽ nền trước
        ui.displayGameScreen(window, score);
        snake.draw(window); // Vẽ rắn sau nền
        food.draw(window);  // Vẽ thức ăn sau rắn
        window.display();
    } else if (gameState == GameState::End) {
        ui.displayEndScreen(window);
    }
}
