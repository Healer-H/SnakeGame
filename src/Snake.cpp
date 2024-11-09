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
