#include <iostream>
#include "Letter.hpp"

Letter::Letter(char ch, State::Context context, const sf::IntRect& textureRect)
  : Button(context), letter(ch)
{
  normalTexture = context.textures->get(Textures::ID::ALPHABET);
  //selectedTexture = context.textures->get(Textures::ID::ALPHABET);
  sprite.setTexture(context.textures->get(Textures::ID::ALPHABET));
  sprite.setTextureRect(textureRect);
}
