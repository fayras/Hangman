#include "Word.hpp"
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
  for(int i = 0; i < orgWord.length(); i++) {
    if(orgWord[i] != ' ') {
      sf::RectangleShape us(sf::Vector2f(35, 2));
      us.move(i * 50, 40);
      target.draw(us, states);
    }
  }
  for(const auto& r : revealed) {
    sf::Text txt(orgWord[r], font);
    txt.move(r * 50 + 10, 0);
    target.draw(txt, states);
  }
}

bool Word::guess(char ch) {
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
    }
  }

  guesses.clear();
}
