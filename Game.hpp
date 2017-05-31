#ifndef HANGMAN_GAME_HPP
#define HANGMAN_GAME_HPP

#include <SFML/Graphics.hpp>
#include "Manikin.hpp"
#include "Word.hpp"
#include "LetterList.hpp"

class Game {
  public:
    Game();
    void run();
    void guess(char ch);

  private:
    void processEvents();
    void render();

    sf::RenderWindow window;
    bool isPaused;

    Word word;
    Manikin manikin;
    std::vector<char> guesses;
    LetterList letters;
};


#endif //HANGMAN_GAME_HPP
