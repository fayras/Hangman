#include <iostream>
#include "Letter.hpp"

Letter::Letter(char ch, const sf::Texture& texture, const sf::IntRect& textureRect)
  : SpriteNode(texture, textureRect), letter(ch)
{}

void Letter::highlight() {

}

void Letter::unhighlight() {

}

bool Letter::intersects(int x, int y) const {
  sf::FloatRect rect = getWorldTransform().transformRect(sprite.getGlobalBounds());
  return rect.contains(x, y);
}

void Letter::setActive(bool active) {
  isActive = active;
}
