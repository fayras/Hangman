#include <iostream>
#include "Letter.hpp"

Letter::Letter(char ch, sf::Font& font)
  : sf::Text(ch, font)
{
  setCharacterSize(45);
}

void Letter::handleEvent(const sf::Event &event, const sf::Transform &transform) {
  sf::FloatRect rect = transform.transformRect(getGlobalBounds());
  if(rect.contains(event.mouseMove.x, event.mouseMove.y)) {
    setFillColor(sf::Color::Red);
  } else {
    setFillColor(sf::Color::White);
  }
}
