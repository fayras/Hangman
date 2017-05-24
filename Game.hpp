#ifndef HANGMAN_GAME_HPP
#define HANGMAN_GAME_HPP

#include <SFML/Graphics.hpp>

class Game {
  public:
    Game();
    void run();

  private:
    void processEvents();
    void update(sf::Time);
    void render();

    sf::RenderWindow window;
    bool isPaused;
};


#endif //HANGMAN_GAME_HPP
