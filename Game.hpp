#ifndef HANGMAN_GAME_HPP
#define HANGMAN_GAME_HPP

#include <SFML/Graphics.hpp>
#include "Manikin.hpp"
#include "Word.hpp"
#include "SceneNode.hpp"
#include "CommandQueue.hpp"
#include "ResourceIdentifiers.hpp"
#include "ResourceHolder.hpp"
#include "StateStack.hpp"
#include "MusicPlayer.hpp"
#include "SoundPlayer.hpp"

class Game {
  public:
    Game();
    void run();

  private:
    void processEvents();
    void update(sf::Time dt);
    void render();

    void registerStates();

    bool isPaused;

    sf::RenderWindow window;
    StateStack stateStack;
    TextureHolder textures;
    FontHolder fonts;
    MusicPlayer	music;
    SoundPlayer	sounds;

    static const sf::Time	TimePerFrame;
};


#endif //HANGMAN_GAME_HPP
