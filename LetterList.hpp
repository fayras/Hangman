#ifndef HANGMAN_LETTERLIST_HPP
#define HANGMAN_LETTERLIST_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Letter.hpp"

class LetterList : public sf::Drawable, public sf::Transformable {
  public:
    LetterList();

  protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  private:
    std::vector<Letter> letters;
};

#endif //HANGMAN_LETTERLIST_HPP
