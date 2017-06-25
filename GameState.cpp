#include "GameState.hpp"
#include "Word.hpp"
#include "Manikin.hpp"
#include "ResourceHolder.hpp"
#include "Letter.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

const int CHARS_PER_ROW = 7;
const int TEXTURE_SIZE = 40;
const int TEXTURE_OFFSET_TO_A = 1320;

GameState::GameState(StateStack &stack, const State::Context &context)
    : State(stack, context)
{
  context.textures->load(Textures::ID::MANIKIN, "../assets/textures/manakin1.png");

  letters.move(500, 400);
  createLetters();

  SceneNode::Ptr manikin(new Manikin(context.textures->get(Textures::ID::MANIKIN)));
  manikin->move(15, 600);
  sceneGraph.attachChild(std::move(manikin));

  SceneNode::Ptr word(new Word("test", context.fonts->get(Fonts::ID::MAIN)));
  word->move(500, 200);
  sceneGraph.attachChild(std::move(word));
}

void GameState::draw() {
  getContext().window->draw(sceneGraph);
  getContext().window->draw(letters);
}

bool GameState::update(sf::Time dt) {
  while(!commandQueue.empty()) {
    sceneGraph.onCommand(commandQueue.pop(), dt);
  }
  sceneGraph.update(dt, commandQueue);

  return true;
}

bool GameState::handleEvent(const sf::Event &event) {
  letters.handleEvent(event);

  // Escape pressed, trigger the pause screen
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    requestStackPush(States::ID::PAUSE);

  return true;
}

void GameState::createLetters() {
  int counter = 0;
  for(int c = 97; c <= 122; c++) {
    std::unique_ptr<Letter> l(new Letter(static_cast<char>(c), context, sf::IntRect(
        TEXTURE_OFFSET_TO_A + (c - 97) * TEXTURE_SIZE, 0, TEXTURE_SIZE, TEXTURE_SIZE
    )));
    l->setCallback([this, c, &commandQueue] () {
      Command command;
      command.category = Category::GUESS;
      command.action = derivedAction<Word>([this, c] (Word& node, sf::Time) {
        if(node.guess(static_cast<char>(c))) {

        } else {

        }
      });
      commandQueue.push(command);
    });
    if(counter >= CHARS_PER_ROW) {
      counter = 0;
    }
    l->move(counter++ * 60, (c - 97) / CHARS_PER_ROW * 50);
    letters.pack(std::move(l));
  }
}
