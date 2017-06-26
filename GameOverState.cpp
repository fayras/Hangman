#include "GameOverState.hpp"
#include "gui/Button.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

GameOverState::GameOverState(StateStack &stack, const State::Context &context)
  : State(stack, context)
{
  sf::Vector2f windowSize(context.window->getSize());

  auto returnButton = std::make_shared<gui::Button>(context);
  returnButton->setPosition(0.5f * windowSize.x - 100, 0.4f * windowSize.y + 55);
  returnButton->setText("Neues Spiel");
  returnButton->setCallback([this] () {
    requestStackClear();
    requestStackPush(States::ID::GAME);
  });

  auto backToMenuButton = std::make_shared<gui::Button>(context);
  backToMenuButton->setPosition(0.5f * windowSize.x - 100, 0.4f * windowSize.y + 125);
  backToMenuButton->setText("Zurück zum Titel");
  backToMenuButton->setCallback([this] () {
    requestStackClear();
    requestStackPush(States::TITLE);
  });

  guiContainer.pack(returnButton);
  guiContainer.pack(backToMenuButton);
}

void GameOverState::draw() {
  sf::RenderWindow& window = *getContext().window;
  window.setView(window.getDefaultView());

  sf::RectangleShape backgroundShape;
  backgroundShape.setFillColor(sf::Color(0, 0, 0, 170));
  backgroundShape.setSize(window.getView().getSize());

  window.draw(backgroundShape);
  window.draw(guiContainer);
}

bool GameOverState::update(sf::Time dt) {
  return false;
}

bool GameOverState::handleEvent(const sf::Event &event) {
  guiContainer.handleEvent(event);
  return false;
}
