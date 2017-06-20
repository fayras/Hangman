#ifndef HANGMAN_LETTERLIST_HPP
#define HANGMAN_LETTERLIST_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>
#include "SceneNode.hpp"
#include "ResourceIdentifiers.hpp"


class LetterList : public SceneNode {
  public:
    explicit LetterList(const TextureHolder& textures);
};

#endif //HANGMAN_LETTERLIST_HPP
