#ifndef HANGMAN_PAUSESTATE_HPP
#define HANGMAN_PAUSESTATE_HPP

#include "State.hpp"
#include "gui/Container.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

class PauseState : public State {
  public:
    PauseState(StateStack& stack, Context context);
    ~PauseState();

    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);

  private:
    sf::Text pausedText;
    gui::Container guiContainer;
};

#endif //HANGMAN_PAUSESTATE_HPP
