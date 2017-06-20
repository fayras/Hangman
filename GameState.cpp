#include "GameState.hpp"
#include "Word.hpp"
#include "Manikin.hpp"
#include "LetterList.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

GameState::GameState(StateStack &stack, const State::Context &context)
    : State(stack, context)
{
  SceneNode::Ptr letters(new LetterList(*context.textures));
  letters->move(500, 400);
  sceneGraph.attachChild(std::move(letters));

  SceneNode::Ptr manikin(new Manikin());
  manikin->move(15, 600);
  sceneGraph.attachChild(std::move(manikin));

  SceneNode::Ptr word(new Word("test"));
  word->move(500, 200);
  sceneGraph.attachChild(std::move(word));
}

void GameState::draw() {
  getContext().window->draw(sceneGraph);
}

bool GameState::update(sf::Time dt) {
  while(!commandQueue.empty()) {
    sceneGraph.onCommand(commandQueue.pop());
  }

  sceneGraph.update(dt);
  return true;
}

bool GameState::handleEvent(const sf::Event &event) {
  // Escape pressed, trigger the pause screen
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    requestStackPush(States::ID::PAUSE);

  return true;
}
