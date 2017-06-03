#include <iostream>
#include "Letter.hpp"

Letter::Letter(char ch, sf::Font& font)
  : letter(ch), text(letter, font)
{
  text.setCharacterSize(45);
}

void Letter::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= getTransform();
  target.draw(text, states);
}

void Letter::handleEvent(const sf::Event &event) {

}
