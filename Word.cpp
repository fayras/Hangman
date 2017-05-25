#include "Word.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

Word::Word(const std::string &word)
    : word(word), font()
{
  font.loadFromFile("../fonts/Roboto.ttf");
}

void Word::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  for(int i = 0; i < word.length(); i++) {
    //target.draw();
  }
  for(const auto& r : revealed) {
    sf::Text txt(word[r], font);
    target.draw(txt, states);
  }
}

bool Word::exists(char ch) {
  return word.find(ch) == std::string::npos;
}

void Word::reveal(char ch) {
  size_t found = word.find(ch);
  while(found != std::string::npos) {
    revealed.push_back(found);
    found = word.find(ch, found + 1);
  }
}
