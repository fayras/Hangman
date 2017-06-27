#include "GameOverState.hpp"
#include "gui/Button.hpp"
#include "MusicPlayer.hpp"
#include "SoundPlayer.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

GameOverState::GameOverState(StateStack &stack, const State::Context &context, Type type)
  : State(stack, context), sprite()
{
  sf::Vector2f windowSize(context.window->getSize());

  if(type == Type::WIN) {
    sprite.setTexture(context.textures->get(Textures::ID::GAME_WIN));
  } else {
    sprite.setTexture(context.textures->get(Textures::ID::GAME_LOSE));
  }
  sf::FloatRect bounds = sprite.getLocalBounds();
  sprite.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
  sprite.setPosition(0.5f * windowSize.x, 0.2f * windowSize.y);

  auto returnButton = std::make_shared<gui::Button>(context);
  returnButton->setPosition(0.5f * windowSize.x - 100, 0.4f * windowSize.y + 55);
  returnButton->setText("Neues Spiel");
  returnButton->setCallback([this] () {
    requestStackClear();
    requestStackPush(States::ID::GAME);
  });

  auto backToMenuButton = std::make_shared<gui::Button>(context);
  backToMenuButton->setPosition(0.5f * windowSize.x - 100, 0.4f * windowSize.y + 125);
  backToMenuButton->setText("Beenden");
  backToMenuButton->setCallback([this] () {
    requestStackClear();
  });

  guiContainer.pack(returnButton);
  guiContainer.pack(backToMenuButton);

  if(type == Type::WIN) {
    context.sounds->play(SoundEffect::WIN);
  } else {
    context.sounds->play(SoundEffect::FAIL);
  }
  context.music->stop();
}

void GameOverState::draw() {
  sf::RenderWindow& window = *getContext().window;
  window.setView(window.getDefaultView());

  sf::RectangleShape backgroundShape;
  backgroundShape.setFillColor(sf::Color(0, 0, 0, 170));
  backgroundShape.setSize(window.getView().getSize());

  window.draw(backgroundShape);
  window.draw(guiContainer);
  window.draw(sprite);
}

bool GameOverState::update(sf::Time dt) {
  return false;
}

bool GameOverState::handleEvent(const sf::Event &event) {
  guiContainer.handleEvent(event);
  return false;
}
