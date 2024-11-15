#include "Game.h"
#include <iostream>
#include <thread>  // Include the thread library for sleep_for
#include <chrono>  // Include the chrono library for milliseconds

Game::Game() : window(sf::VideoMode(800, 600), "SnakeGame"), score(0), currentState(GameState::StartScreen) {
    // Initialize Start Button
    startButton.setSize(sf::Vector2f(200, 50));
    startButton.setFillColor(sf::Color::Green);
    startButton.setPosition(300, 250);

    // Initialize Replay Button
    replayButton.setSize(sf::Vector2f(200, 50));
    replayButton.setFillColor(sf::Color::Yellow);
    replayButton.setPosition(300, 300);

    std::cout << "Game initialized" << std::endl;
}

void Game::run() {
    while (window.isOpen()) {
        processInput();

        switch (currentState) {
        case GameState::StartScreen:
            renderStartScreen();
            break;
        case GameState::Playing:
            update();
            render();
            break;
        case GameState::EndScreen:
            renderEndScreen();
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Sleep for 500 milliseconds
    }
}

void Game::processInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (currentState == GameState::StartScreen && event.type == sf::Event::MouseButtonPressed) {
            if (startButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                currentState = GameState::Playing;
                snake = Snake();
                food.spawn(window.getSize());
                score = 0;
            }
        }

        if (currentState == GameState::EndScreen && event.type == sf::Event::MouseButtonPressed) {
            if (replayButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                currentState = GameState::Playing;
                snake = Snake();
                food.spawn(window.getSize());
                score = 0;
            }
        }

        if (currentState == GameState::Playing && event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
            case sf::Keyboard::Up:
                snake.setDirection(sf::Vector2f(0, -1));
                break;
            case sf::Keyboard::Down:
                snake.setDirection(sf::Vector2f(0, 1));
                break;
            case sf::Keyboard::Left:
                snake.setDirection(sf::Vector2f(-1, 0));
                break;
            case sf::Keyboard::Right:
                snake.setDirection(sf::Vector2f(1, 0));
                break;
            default:
                break;
            }
        }
    }
}

void Game::update() {
    if (currentState != GameState::Playing) return;

    snake.move(window.getSize());

    // Check if the snake eats food
    if (snake.getHeadPosition() == food.getPosition()) {
        snake.grow();
        score += 10;
        food.spawn(window.getSize());
    }

    // Check if the snake collides with itself
    if (snake.checkCollision(window.getSize())) {
        currentState = GameState::EndScreen;
    }
}

void Game::render() {
    if (currentState != GameState::Playing) return;

    window.clear();
    ui.displayScore(window, score);
    snake.draw(window);
    food.draw(window);
    window.display();
}

void Game::renderStartScreen() {
    window.clear();

    sf::Text startTextButton;
    startTextButton.setFont(ui.getFont());
    startTextButton.setString("Start Game");
    startTextButton.setCharacterSize(24);
    startTextButton.setFillColor(sf::Color::Black);
    startTextButton.setPosition(330, 260);

    sf::Text startText;
    startText.setFont(ui.getFont());
    startText.setString("SS004.P12");
    startText.setCharacterSize(26);
    startText.setFillColor(sf::Color::White);
    startText.setPosition(310, 180);

    window.draw(startButton);
    window.draw(startTextButton);
    window.draw(startText);
    window.display();
}

void Game::renderEndScreen() {
    window.clear();

    ui.displayGameOver(window);

    sf::Text replayText;
    replayText.setFont(ui.getFont());
    replayText.setString("Replay");
    replayText.setCharacterSize(24);
    replayText.setFillColor(sf::Color::Black);
    replayText.setPosition(360, 310);

    window.draw(replayButton);
    window.draw(replayText);
    window.display();
}
