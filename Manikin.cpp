#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "Manikin.hpp"

Manikin::Manikin(const sf::Texture& texture)
    : SpriteNode(texture, sf::IntRect(0, 0, 400, 500)), attempts(1), maxAttempts(10)
{}

unsigned int Manikin::getCategory() const {
  return Category::MANIKIN;
}

void Manikin::advance() {
  attempts++;
  sf::IntRect rect = sprite.getTextureRect();
  rect.left += 400;
  sprite.setTextureRect(rect);
}

void Manikin::updateCurrent(sf::Time dt, CommandQueue &commands) {

}

bool Manikin::dead() const {
  return attempts >= maxAttempts;
}
