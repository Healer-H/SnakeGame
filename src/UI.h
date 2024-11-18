#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>

class UI {
public:
    UI(); // Constructor
    void displayStartScreen(sf::RenderWindow& window);   // Hiển thị màn hình Start
    void displayGameScreen(sf::RenderWindow& window, int score); // Hiển thị màn chơi
    void displayEndScreen(sf::RenderWindow& window);     // Hiển thị màn hình End

    bool isButtonClicked(const sf::RenderWindow& window, const sf::Sprite& button); // Kiểm tra nút được nhấn

    // Getter functions
    sf::Sprite& getPlayButton();
    sf::Sprite& getReplayButton();
    sf::FloatRect getPlayArea() const;

    // New getter for textures
    const sf::Sprite& getBackgroundSprite() const; // Getter cho background
    const sf::Texture& getSnakeHeadTexture() const;
    const sf::Texture& getSnakeBodyTexture() const;

private:
    sf::Font font;
    sf::Text titleText;
    sf::Text scoreText;
    sf::Text gameOverText;

    sf::Texture playButtonTexture;
    sf::Sprite playButton;

    sf::Texture replayButtonTexture;
    sf::Sprite replayButton;

    sf::Texture backgroundTexture; // Texture cho background
    sf::Sprite backgroundSprite;   // Sprite cho background

    sf::Texture snakeHeadTexture;  // Texture cho đầu rắn
    sf::Texture snakeBodyTexture;  // Texture cho thân rắn

    sf::FloatRect playArea;        // Vùng PlayArea
};

#endif
