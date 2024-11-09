#include "Game.h"
#include <iostream>
#include <thread>  // Include the thread library for sleep_for
#include <chrono>  // Include the chrono library for milliseconds

Game::Game() : window(sf::VideoMode(800, 600), "SnakeGame"), score(0) {
    std::cout << "Hello World!" << std::endl;
    // Khởi tạo trò chơi
    snake = Snake();
    food = Food();
    ui = UI();
    std::cout << "Game initialized" << std::endl;
}

void Game::run() {
    std::cout << "Game started" << std::endl;
    while (window.isOpen()) {
        processInput();
        update();
        render();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Sleep for 500 milliseconds
    }
    std::cout << "Game ended" << std::endl;
}

void Game::processInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        
        // Use KeyPressed to handle basic non-Unicode input
        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::Up:
                    snake.setDirection(sf::Vector2f(0, -1));  // Move up
                    break;
                case sf::Keyboard::Down:
                    snake.setDirection(sf::Vector2f(0, 1));   // Move down
                    break;
                case sf::Keyboard::Left:
                    snake.setDirection(sf::Vector2f(-1, 0));  // Move left
                    break;
                case sf::Keyboard::Right:
                    snake.setDirection(sf::Vector2f(1, 0));   // Move right
                    break;
                default:
                    break;
            }
        }
    }
}

void Game::update() {
    std::cout << "Updating game state" << std::endl;
    // Di chuyển rắn
    snake.move(window.getSize());

    // Log the positions of the snake and the food
    std::cout << "Snake head position: " << snake.getHeadPosition().x << ", " << snake.getHeadPosition().y << std::endl;
    std::cout << "Food position: " << food.getPosition().x << ", " << food.getPosition().y << std::endl;

    // Kiểm tra va chạm của rắn với thức ăn
    if (snake.getHeadPosition() == food.getPosition()) {
        snake.grow();          // Tăng chiều dài rắn
        score += 10;           // Tăng điểm số
        food.spawn(window.getSize());  // Sinh thức ăn mới
        std::cout << "Snake ate food, score: " << score << std::endl;
    }

    // Kiểm tra va chạm của rắn với chính thân hoặc tường
    if (snake.checkCollision(window.getSize())) {
        ui.displayGameOver(window);   // Hiển thị "Game Over" nếu va chạm xảy ra
        window.close();
        std::cout << "Collision detected, game over" << std::endl;
    }
}
void Game::render() {
    std::cout << "Rendering game" << std::endl;
    window.clear();
    ui.displayScore(window, score);
    snake.draw(window);
    food.draw(window);
    window.display();
}