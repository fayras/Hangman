#include "LetterList.hpp"

const int CHARS_PER_ROW = 7;

LetterList::LetterList() {
  font.loadFromFile("../fonts/Roboto.ttf");
  int counter = 0;
  for(int c = 65; c <= 90; c++) {
    Letter l{static_cast<char>(c), font};
    if(counter >= CHARS_PER_ROW) {
      counter = 0;
    }
    l.move(counter++ * 60, (c - 65) / CHARS_PER_ROW * 50);
    letters.push_back(l);
  }
}

void LetterList::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= getTransform();
  for(const Letter& l : letters) {
    target.draw(l, states);
  }
}

void LetterList::handleEvent(const sf::Event &event) {
  for(Letter& l : letters) {
    l.handleEvent(event, getTransform());
  }
}
