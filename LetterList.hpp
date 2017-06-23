#ifndef HANGMAN_LETTERLIST_HPP
#define HANGMAN_LETTERLIST_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>
#include "SceneNode.hpp"
#include "ResourceIdentifiers.hpp"
#include "gui/Container.hpp"
#include "State.hpp"
#include "CommandQueue.hpp"


class LetterList : public gui::Container {
  public:
    explicit LetterList(State::Context context, CommandQueue& commandQueue);
};

#endif //HANGMAN_LETTERLIST_HPP
