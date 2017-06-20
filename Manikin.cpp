#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "Manikin.hpp"

Manikin::Manikin()
    : parts()
{
  std::unique_ptr<sf::RectangleShape> base(new sf::RectangleShape(sf::Vector2f(300, 4)));
  parts.push_back(std::move(base));

  std::unique_ptr<sf::RectangleShape> rect1(new sf::RectangleShape(sf::Vector2f(4, -450)));
  rect1->move(150, 0);
  parts.push_back(std::move(rect1));

  std::unique_ptr<sf::RectangleShape> rect2(new sf::RectangleShape(sf::Vector2f(200, 4)));
  rect2->move(150, -450);
  parts.push_back(std::move(rect2));

  std::unique_ptr<sf::RectangleShape> rect3(new sf::RectangleShape(sf::Vector2f(4, 50)));
  rect3->move(350, -450);
  parts.push_back(std::move(rect3));

  std::unique_ptr<sf::CircleShape> head(new sf::CircleShape(40));
  head->setOrigin(40, 0);
  head->move(350, -400);
  parts.push_back(std::move(head));

  attempts = parts.size();
}

void Manikin::next() {
  if(alive()) {
    attempts--;
  }
}

bool Manikin::alive() const {
  return attempts > 0;
}
