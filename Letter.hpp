#ifndef HANGMAN_LETTER_HPP
#define HANGMAN_LETTER_HPP

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>

class Letter : public sf::Text {
  public:
    Letter(char ch, sf::Font& font);
    void handleEvent(const sf::Event &event, const sf::Transform &transform);
};

#endif //HANGMAN_LETTER_HPP
