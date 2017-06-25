#ifndef HANGMAN_GAMESTATE_HPP
#define HANGMAN_GAMESTATE_HPP

#include "State.hpp"
#include "CommandQueue.hpp"
#include "SceneNode.hpp"
#include "gui/Container.hpp"

class GameState : public State {
  public:
    GameState(StateStack &stack, const Context &context);

    void draw() override;
    bool update(sf::Time dt) override;
    bool handleEvent(const sf::Event &event) override;

  private:
    void createLetters();

    SceneNode sceneGraph;
    CommandQueue commandQueue;
    gui::Container letters;
};


#endif //HANGMAN_GAMESTATE_HPP
