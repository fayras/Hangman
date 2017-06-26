#ifndef HANGMAN_LETTER_HPP
#define HANGMAN_LETTER_HPP

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include "SpriteNode.hpp"
#include "gui/Button.hpp"

class Letter : public gui::Button {
  public:
    explicit Letter(char ch, State::Context context, const sf::IntRect& textureRect);
    void select() override;
    void deselect() override;
    void activate() override;

  private:
    char letter;
    bool clicked;
};

#endif //HANGMAN_LETTER_HPP
