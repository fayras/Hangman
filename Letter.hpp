#ifndef HANGMAN_LETTER_HPP
#define HANGMAN_LETTER_HPP

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include "SpriteNode.hpp"

class Letter : public SpriteNode {
  public:
    Letter(char ch, const sf::Texture& texture, const sf::IntRect& textureRect);
    bool intersects(int x, int y) const;
    void setActive(bool active);
    void highlight();
    void unhighlight();

  private:
    bool isActive;
    char letter;
};

#endif //HANGMAN_LETTER_HPP
