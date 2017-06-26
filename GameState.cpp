#include "GameState.hpp"
#include "Word.hpp"
#include "Manikin.hpp"
#include "ResourceHolder.hpp"
#include "Letter.hpp"
#include "SoundNode.hpp"
#include "MusicPlayer.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <fstream>
#include <iostream>

const int CHARS_PER_ROW = 7;
const int TEXTURE_SIZE = 40;
const int TEXTURE_OFFSET_TO_A = 1320;

namespace {
  std::default_random_engine createRandomEngine() {
    auto seed = static_cast<unsigned long>(std::time(nullptr));
    return std::default_random_engine(seed);
  }
  auto RandomEngine = createRandomEngine();
}

GameState::GameState(StateStack &stack, const State::Context &context)
    : State(stack, context)
{
  letters.move(500, 400);
  createLetters();

  std::ifstream inFile("../assets/dict.txt");
  unsigned lineCount = (unsigned) std::count(std::istreambuf_iterator<char>(inFile), std::istreambuf_iterator<char>(), '\n');
  std::uniform_int_distribution<> distr(0, lineCount - 1);
  unsigned lineNum = (unsigned) distr(RandomEngine);
  std::string line;

  if (inFile.is_open()) {
    inFile.clear();
    inFile.seekg(0, inFile.beg);
    for(unsigned l = 0; !inFile.eof(); l++) {
      std::getline(inFile, line);
      if(l == lineNum) break;
    }
    inFile.close();
  }

  SceneNode::Ptr bg(new SpriteNode(context.textures->get(Textures::ID::GAME_BG)));
  sceneGraph.attachChild(std::move(bg));

  manikin = new Manikin(context.textures->get(Textures::ID::MANIKIN));
  SceneNode::Ptr mk(manikin);
  mk->move(15, 160);
  sceneGraph.attachChild(std::move(mk));

  word = new Word(line, context.fonts->get(Fonts::ID::MAIN));
  SceneNode::Ptr wrd(word);
  wrd->move(context.window->getSize().x * 0.5f, 100);
  sceneGraph.attachChild(std::move(wrd));

  std::unique_ptr<SoundNode> sound(new SoundNode(*context.sounds));
  sceneGraph.attachChild(std::move(sound));

  context.music->play(Music::GAME);
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
    requestStackPush(States::ID::GAME_OVER);
  }

  if(word->finished()) {
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
