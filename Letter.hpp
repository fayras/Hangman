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
    bool intersects(int x, int y, const sf::Transform &transform) const;
    void setActive(bool active);
    void highlight();
    void unhighlight();

  private:
    bool isActive;
};

#endif //HANGMAN_LETTER_HPP
