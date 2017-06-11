#include <iostream>
#include "Letter.hpp"

Letter::Letter(char ch, sf::Font& font)
  : sf::Text(ch, font), isActive(true)
{
  setCharacterSize(45);
}

void Letter::highlight() {
  setFillColor(sf::Color::Red);
}

void Letter::unhighlight() {
  setFillColor(sf::Color::White);
}

bool Letter::intersects(int x, int y, const sf::Transform &transform) const {
  sf::FloatRect rect = transform.transformRect(getGlobalBounds());
  return rect.contains(x, y);
}

void Letter::setActive(bool active) {
  isActive = active;
}
