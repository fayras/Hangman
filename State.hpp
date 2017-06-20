#ifndef HANGMAN_STATE_HPP
#define HANGMAN_STATE_HPP

#include "StateIdentifiers.hpp"
#include "ResourceIdentifiers.hpp"

namespace sf {
  class RenderWindow;
}

class StateStack;

class State {
  public:
    typedef std::unique_ptr<State> Ptr;

    struct Context {
      Contex(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts);
      sf::RenderWindow* window;
      TextureHolder* textures;
      FontHolder* fonts;
    };

    State(StateStack& stack, Context context);
    virtual ~State();

    virtual void draw() = 0;
    virtual void update(sf::Time dt) = 0;
    virtual void handleEvent(const sf::Event& event) = 0;

  protected:
    void requestStackPush(States::ID stateID);
    void requestStackPop();
    void requestStackClear();
    Context getContext() const;

  private:
    StateStack* stack;
    Context context;
};

#endif //HANGMAN_STATE_HPP