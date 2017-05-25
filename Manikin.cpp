#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "Manikin.hpp"

Manikin::Manikin()
    : parts()
{
  std::unique_ptr<sf::RectangleShape> base(new sf::RectangleShape(sf::Vector2f(300, 4)));
  base->move(15, 600);
  parts.push_back(std::move(base));

  std::unique_ptr<sf::RectangleShape> rect1(new sf::RectangleShape(sf::Vector2f(4, 450)));
  rect1->move(165, 150);
  parts.push_back(std::move(rect1));
  std::unique_ptr<sf::RectangleShape> rect2(new sf::RectangleShape(sf::Vector2f(200, 4)));
  rect2->move(165, 150);
  parts.push_back(std::move(rect2));
  std::unique_ptr<sf::RectangleShape> rect3(new sf::RectangleShape(sf::Vector2f(4, 50)));
  rect3->move(365, 150);
  parts.push_back(std::move(rect3));
  std::unique_ptr<sf::CircleShape> head(new sf::CircleShape(40));
  head->move(325, 190);
  parts.push_back(std::move(head));

  attempts = parts.size();
}

void Manikin::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  for(int i = 0; i < parts.size() - attempts; i++) {
    target.draw(*(parts[i]), states);
  }
}

bool Manikin::next() {
  if(attempts == 0) return false;
  attempts -= 1;
  return attempts > 0;
}
