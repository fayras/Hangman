#include "Letter.hpp"

Letter::Letter(char ch, State::Context context, const sf::IntRect& textureRect)
  : Button(context), letter(ch), clicked(false)
{
  normalTexture = context.textures->get(Textures::ID::ALPHABET);
  selectedTexture = context.textures->get(Textures::ID::ALPHABET);
  sprite.setTexture(context.textures->get(Textures::ID::ALPHABET));
  sprite.setTextureRect(textureRect);
  sf::FloatRect bounds = sprite.getLocalBounds();
  sprite.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

void Letter::select() {
  if(clicked) return;

  gui::Button::select();
  sprite.setScale(1.4, 1.4);
}

void Letter::deselect() {
  gui::Button::deselect();
  sprite.setScale(1, 1);
}

void Letter::activate() {
  if(clicked) return;

  gui::Button::activate();
  clicked = true;
  sf::IntRect rect = sprite.getTextureRect();
  rect.top = rect.top + 40;
  sprite.setTextureRect(rect);
  deselect();
}
