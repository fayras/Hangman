#include "LetterList.hpp"
#include "Letter.hpp"
#include "ResourceHolder.hpp"

const int CHARS_PER_ROW = 7;
const int TEXTURE_SIZE = 40;
const int TEXTURE_OFFSET_TO_A = 1320;

LetterList::LetterList(const TextureHolder &textures) {
  int counter = 0;
  for(int c = 65; c <= 90; c++) {
    std::unique_ptr<SpriteNode> l(new Letter(static_cast<char>(c), textures.get(Textures::ID::ALPHABET), sf::IntRect(
        TEXTURE_OFFSET_TO_A + (c - 65) * TEXTURE_SIZE, 0, TEXTURE_SIZE, TEXTURE_SIZE
    )));
    if(counter >= CHARS_PER_ROW) {
      counter = 0;
    }
    l->move(counter++ * 60, (c - 65) / CHARS_PER_ROW * 50);
    attachChild(std::move(l));
  }
}
