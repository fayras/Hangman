#include "Letter.hpp"

Letter::Letter(char ch)
  : letter(ch), font()
{
  font.loadFromFile("../fonts/Roboto.ttf");
}

void Letter::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= getTransform();
  sf::Text text(letter, font);
  text.setCharacterSize(45);
  target.draw(text, states);
}
