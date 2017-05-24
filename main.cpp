#include <iostream>
#include "Game.hpp"

int main() {
  try {
    Game game;
    game.run();
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  return 0;
}