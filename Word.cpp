#include "Word.hpp"
#include "SoundNode.hpp"
#include "Manikin.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>

Word::Word(std::string pWord, const sf::Font& font)
    : orgWord(pWord), word(pWord), font(font)
{
  std::transform(word.begin(), word.end(), word.begin(), ::tolower);
  reveal(' ');
}

void Word::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
  sf::RectangleShape bg(sf::Vector2f(orgWord.length() * 50, 50));
  bg.setFillColor(sf::Color(0, 0, 0, 100));
  target.draw(bg, states);

  for(int i = 0; i < orgWord.length(); i++) {
    if(orgWord[i] != ' ') {
      sf::RectangleShape us(sf::Vector2f(35, 2));
      us.move(i * 50 + 7, 40);
      target.draw(us, states);
    }
  }
  for(const auto& r : revealed) {
    sf::Text txt(orgWord[r], font);
    txt.move(r * 50 + 14, 0);
    target.draw(txt, states);
  }
}

void Word::guess(char ch) {
  //ch = (char) ::tolower(ch);
  guesses.push_back(ch);
}

bool Word::exists(char ch) {
  return word.find(ch) != std::string::npos;
}

bool Word::finished() const {
  return revealed.size() == word.length();
}

void Word::reveal(char ch) {
  size_t found = word.find(ch);
  while(found != std::string::npos) {
    revealed.push_back(found);
    found = word.find(ch, found + 1);
  }
}

unsigned int Word::getCategory() const {
  return Category::GUESS;
}

void Word::updateCurrent(sf::Time dt, CommandQueue &commands) {
  for(char& guess : guesses) {
    if(exists(guess)) {
      reveal(guess);
      Command command;
      command.category = Category::SOUND_EFFECT;
      command.action = derivedAction<SoundNode>([this] (SoundNode& node, sf::Time dt) {
        node.playSound(SoundEffect::ID::GUESS_RIGHT, getPosition());
      });
      commands.push(command);
    } else {
      Command command;
      command.category = Category::SOUND_EFFECT;
      command.action = derivedAction<SoundNode>([this] (SoundNode& node, sf::Time dt) {
        node.playSound(SoundEffect::ID::GUESS_FAIL, getPosition());
      });
      commands.push(command);

      Command command2;
      command2.category = Category::MANIKIN;
      command2.action = derivedAction<Manikin>([] (Manikin& manikin, sf::Time dt) {
        manikin.advance();
      });
      commands.push(command2);
    }
  }

  guesses.clear();
}
