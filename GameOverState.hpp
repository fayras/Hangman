#ifndef HANGMAN_GAMEOVERSTATE_HPP
#define HANGMAN_GAMEOVERSTATE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include "State.hpp"
#include "gui/Container.hpp"

class GameOverState : public State {
  public:
    enum Type { LOSE, WIN };

    GameOverState(StateStack &stack, const Context &context, Type type);

    void draw() override;
    bool update(sf::Time dt) override;
    bool handleEvent(const sf::Event &event) override;

  private:
    gui::Container guiContainer;
    sf::Sprite sprite;
};


#endif //HANGMAN_GAMEOVERSTATE_HPP
