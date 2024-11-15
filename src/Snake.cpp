#include "Game.h"

void Snake::move(const sf::Vector2u& windowSize) {
    // Move the snake's body
    for (int i = body.size() - 1; i > 0; --i) {
        body[i].setPosition(body[i - 1].getPosition());
    }
    body[0].move(direction * 10.0f);

    // Wrap around the screen
    sf::Vector2f headPos = body[0].getPosition();
    if (headPos.x < 0) {
        headPos.x = windowSize.x - 10;
    } else if (headPos.x >= windowSize.x) {
        headPos.x = 0;
    }
    if (headPos.y < 0) {
        headPos.y = windowSize.y - 10;
    } else if (headPos.y >= windowSize.y) {
        headPos.y = 0;
    }
    body[0].setPosition(headPos);
}

void Snake::grow() {
    // Add a new segment to the snake's body at the position of the last segment
    sf::RectangleShape newSegment(sf::Vector2f(10, 10));
    newSegment.setFillColor(sf::Color::Green);
    newSegment.setPosition(body.back().getPosition());
    body.push_back(newSegment);
}

bool Snake::checkCollision(const sf::Vector2u& windowSize) const {
    // Check collision with the snake's body
    for (int i = 1; i < body.size(); ++i) {
        if (body[0].getPosition() == body[i].getPosition()) {
            return true;
        }
    }
    return false;
}


void Snake::draw(sf::RenderWindow& window) const {
    for (const auto& segment : body) {
        window.draw(segment);
    }
}