#include "UI.h"
#include <string>
#include <iostream>

UI::UI() {
    // Load font
    if (!font.loadFromFile("assets/fonts/Montserrat-Bold.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
    }

    // Load background
    if (!backgroundTexture.loadFromFile("assets/images/background.png")) {
        std::cerr << "Failed to load background texture!" << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture);

    // Define PlayArea
    playArea = sf::FloatRect(0, 105 , 800, 495);

    // Load textures for Snake Head and Body
    if (!snakeHeadTexture.loadFromFile("assets/images/head_no_alpha.png")) {
        std::cerr << "Failed to load head texture!" << std::endl;
    } else {
        std::cout << "Head texture loaded successfully!" << std::endl;
    }

    if (!snakeBodyTexture.loadFromFile("assets/images/body_no_alpha.png")) {
        std::cerr << "Failed to load body texture!" << std::endl;
    } else {
        std::cout << "Body texture loaded successfully!" << std::endl;
    }

    // Title Text
    titleText.setFont(font);
    titleText.setString("Snake Game");
    titleText.setCharacterSize(32);
    titleText.setFillColor(sf::Color::Red);
    titleText.setPosition(300, 200); // Vị trí thay đổi để cân đối trên nền

    // Score Text
    scoreText.setFont(font);
    scoreText.setCharacterSize(32);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(50, 20);

    // Game Over Text
    gameOverText.setFont(font);
    gameOverText.setString("Game Over!");
    gameOverText.setCharacterSize(32);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(300, 200);

    // Play Button
    if (!playButtonTexture.loadFromFile("assets/images/play.png")) { // Cập nhật ảnh play.png
        std::cerr << "Failed to load play button texture!" << std::endl;
    }
    playButton.setTexture(playButtonTexture);
    playButton.setPosition(332, 277); // Căn giữa theo kích thước cửa sổ mới

    // Replay Button
    if (!replayButtonTexture.loadFromFile("assets/images/replay.png")) {
        std::cerr << "Failed to load replay button texture!" << std::endl;
    }
    replayButton.setTexture(replayButtonTexture);
    replayButton.setPosition(332, 277); // Giữ vị trí tương tự nút Play
}

void UI::displayStartScreen(sf::RenderWindow& window) {
    window.clear();
    window.draw(backgroundSprite);
    window.draw(titleText);
    window.draw(playButton);
    window.display();
}

void UI::displayGameScreen(sf::RenderWindow& window, int score) {
    window.draw(backgroundSprite);
    scoreText.setString("Score: " + std::to_string(score));
    window.draw(scoreText);
}

void UI::displayEndScreen(sf::RenderWindow& window) {
    window.clear();
    window.draw(backgroundSprite);
    window.draw(gameOverText);
    window.draw(replayButton);
    window.display();
}

bool UI::isButtonClicked(const sf::RenderWindow& window, const sf::Sprite& button) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (button.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            return true;
        }
    }
    return false;
}

// Getter for Snake Head Texture
const sf::Texture& UI::getSnakeHeadTexture() const {
    return snakeHeadTexture;
}

// Getter for Snake Body Texture
const sf::Texture& UI::getSnakeBodyTexture() const {
    return snakeBodyTexture;
}

const sf::Sprite& UI::getBackgroundSprite() const {
    return backgroundSprite;
}

sf::Sprite& UI::getPlayButton() {
    return playButton;
}

sf::Sprite& UI::getReplayButton() {
    return replayButton;
}

sf::FloatRect UI::getPlayArea() const {
    return playArea;
}
