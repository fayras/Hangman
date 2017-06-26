#ifndef HANGMAN_GAMEOVERSTATE_HPP
#define HANGMAN_GAMEOVERSTATE_HPP

#include "State.hpp"
#include "gui/Container.hpp"

class GameOverState : public State {
  public:
    GameOverState(StateStack &stack, const Context &context);

    void draw() override;
    bool update(sf::Time dt) override;
    bool handleEvent(const sf::Event &event) override;

  private:
    gui::Container guiContainer;
};


#endif //HANGMAN_GAMEOVERSTATE_HPP
