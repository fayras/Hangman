#ifndef HANGMAN_LETTER_HPP
#define HANGMAN_LETTER_HPP

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>

class Letter : public sf::Drawable, public sf::Transformable {
  public:
    Letter(char ch, sf::Font& font);
    void handleEvent(const sf::Event &event);

  protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  private:
    char letter;
    sf::Text text;
};

#endif //HANGMAN_LETTER_HPP
