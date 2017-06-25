#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "Manikin.hpp"

Manikin::Manikin(const sf::Texture& texture)
    : SpriteNode(texture)
{}

unsigned int Manikin::getCategory() const {
  return Category::MANIKIN;
}
