#ifndef HANGMAN_TITLESTATE_HPP
#define HANGMAN_TITLESTATE_HPP

#include "State.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

class TitleState : public State {
  public:
    TitleState(StateStack& stack, Context context);
    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);

  private:
    sf::Sprite background;
};


#endif //HANGMAN_TITLESTATE_HPP
