#ifndef HANGMAN_LETTERLIST_HPP
#define HANGMAN_LETTERLIST_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>
#include "Letter.hpp"

class LetterList : public sf::Drawable, public sf::Transformable {
  public:
    LetterList();
    void handleEvent(const sf::Event &event);

  protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  private:
    std::vector<Letter> letters;
    sf::Font font;
};

#endif //HANGMAN_LETTERLIST_HPP
