#include "GameState.hpp"
#include "Word.hpp"
#include "Manikin.hpp"
#include "ResourceHolder.hpp"
#include "Letter.hpp"
#include "SoundNode.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

const int CHARS_PER_ROW = 7;
const int TEXTURE_SIZE = 40;
const int TEXTURE_OFFSET_TO_A = 1320;

GameState::GameState(StateStack &stack, const State::Context &context)
    : State(stack, context)
{
  context.textures->load(Textures::ID::MANIKIN, "../assets/textures/manikin.png");
  context.textures->load(Textures::ID::GAME_BG, "../assets/textures/game_bg.png");

  letters.move(500, 400);
  createLetters();

  SceneNode::Ptr bg(new SpriteNode(context.textures->get(Textures::ID::GAME_BG)));
  sceneGraph.attachChild(std::move(bg));

  manikin = new Manikin(context.textures->get(Textures::ID::MANIKIN));
  SceneNode::Ptr mk(manikin);
  mk->move(15, 160);
  sceneGraph.attachChild(std::move(mk));

  word = new Word("Hangman", context.fonts->get(Fonts::ID::MAIN));
  SceneNode::Ptr wrd(word);
  wrd->move(500, 200);
  sceneGraph.attachChild(std::move(wrd));

  std::unique_ptr<SoundNode> sound(new SoundNode(*context.sounds));
  sceneGraph.attachChild(std::move(sound));
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

  if(manikin->dead()) {
    requestStackPop();
    requestStackPush(States::ID::GAME_OVER);
  }

  if(word->finished()) {
    requestStackPop();
    requestStackPush(States::ID::GAME_OVER_WIN);
  }

  return true;
}

bool GameState::handleEvent(const sf::Event &event) {
  letters.handleEvent(event);

  // Escape pressed, trigger the pause screen
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    requestStackPush(States::ID::PAUSE);

  if(event.type == sf::Event::TextEntered) {
    if(event.key.code >= 65 && event.key.code <= 122) {
      sf::Keyboard::Key key = event.key.code;
      Command command;
      command.category = Category::GUESS;
      command.action = derivedAction<Word>([this, key] (Word& node, sf::Time) {
        node.guess(static_cast<char>(::tolower(key)));
      });
      commandQueue.push(command);
    }
  }

  return true;
}

void GameState::createLetters() {
  int counter = 0;
  for(int c = 97; c <= 122; c++) {
    std::unique_ptr<Letter> l(new Letter(static_cast<char>(c), context, sf::IntRect(
        TEXTURE_OFFSET_TO_A + (c - 97) * TEXTURE_SIZE, 0, TEXTURE_SIZE, TEXTURE_SIZE
    )));
    l->setCallback([this, c] () {
      Command command;
      command.category = Category::GUESS;
      command.action = derivedAction<Word>([this, c] (Word& node, sf::Time) {
        node.guess(static_cast<char>(c));
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
