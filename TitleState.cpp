#include "TitleState.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include "ResourceHolder.hpp"

TitleState::TitleState(StateStack &stack, State::Context context)
    : State(stack, context), background(context.textures->get(Textures::ID::TITLE_BG))
{
}

void TitleState::draw() {
  sf::RenderWindow& window = *getContext().window;
  window.setView(window.getDefaultView());
  window.draw(background);
}

bool TitleState::update(sf::Time dt) {
  return true;
}

bool TitleState::handleEvent(const sf::Event &event) {
  // If any key is pressed, trigger the next screen
  if (event.type == sf::Event::KeyReleased)
  {
    requestStackPop();
    requestStackPush(States::ID::GAME);
  }

  return true;
}
