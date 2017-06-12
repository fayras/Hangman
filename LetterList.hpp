#ifndef HANGMAN_LETTERLIST_HPP
#define HANGMAN_LETTERLIST_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>
#include "Letter.hpp"
#include "SceneNode.hpp"

class LetterList : public SceneNode {
  public:
    LetterList();

  private:
    sf::Font font;
};

#endif //HANGMAN_LETTERLIST_HPP
