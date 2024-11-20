#include "Game.h"
#include <ctime>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    Game game;
    game.run();  // Bắt đầu trò chơi
    return 0;
}
