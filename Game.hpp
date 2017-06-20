#ifndef HANGMAN_GAME_HPP
#define HANGMAN_GAME_HPP

#include <SFML/Graphics.hpp>
#include "Manikin.hpp"
#include "Word.hpp"
#include "LetterList.hpp"
#include "SceneNode.hpp"
#include "CommandQueue.hpp"
#include "ResourceIdentifiers.hpp"
#include "ResourceHolder.hpp"

class Game {
  public:
    Game();
    void run();
    void guess(char ch);

  private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow window;
    bool isPaused;

    SceneNode sceneGraph;
    CommandQueue commandQueue;
    TextureHolder textures;

    std::vector<char> guesses;

    static const sf::Time	TimePerFrame;
};


#endif //HANGMAN_GAME_HPP
