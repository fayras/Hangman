#include <iostream>
#include "Game.hpp"
#include "GameState.hpp"
#include "TitleState.hpp"
#include "GameOverState.hpp"

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
    : window(sf::VideoMode(1000, 740), "Hangman"),
      isPaused(false),
      stateStack(State::Context(window, textures, fonts, music, sounds))
{
  window.setFramerateLimit(30);
  fonts.load(Fonts::ID::MAIN, "../assets/fonts/Roboto.ttf");
  textures.load(Textures::ID::ALPHABET, "../assets/textures/alphabet.png");
  textures.load(Textures::ID::TITLE_BG, "../assets/textures/title_bg.jpg");
  textures.load(Textures::ID::BUTTON_NORMAL, "../assets/textures/buttons.png", sf::IntRect(0, 0, 200, 50));
  textures.load(Textures::ID::BUTTON_SELECTED, "../assets/textures/buttons.png", sf::IntRect(0, 50, 200, 50));
  textures.load(Textures::ID::BUTTON_PRESSED, "../assets/textures/buttons.png", sf::IntRect(0, 100, 200, 50));
  textures.load(Textures::ID::MANIKIN, "../assets/textures/manikin.png");
  textures.load(Textures::ID::GAME_BG, "../assets/textures/game_bg.png");

  registerStates();
  stateStack.push(States::ID::TITLE);
}

void Game::run() {
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  while (window.isOpen()) {
    sf::Time dt = clock.restart();
    timeSinceLastUpdate += dt;
    while (timeSinceLastUpdate > TimePerFrame) {
      timeSinceLastUpdate -= TimePerFrame;

      processEvents();
      if(!isPaused) {
        update(TimePerFrame);
      }

      if(stateStack.empty()) {
        window.close();
      }
    }
    render();
  }
}

void Game::processEvents() {
  sf::Event event;
  while (window.pollEvent(event)) {

    if(!isPaused) stateStack.handleEvent(event);

    switch (event.type) {
      case sf::Event::GainedFocus:
        isPaused = false;
        break;
      case sf::Event::LostFocus:
        isPaused = true;
        break;
      case sf::Event::Closed:
        window.close();
        break;
      default:
        break;
    }
  }
}

void Game::update(sf::Time dt) {
  stateStack.update(dt);
}

void Game::render() {
  window.clear();
  stateStack.draw();
  window.setView(window.getDefaultView());
  window.display();
}

void Game::registerStates() {
  stateStack.registerState<TitleState>(States::ID::TITLE);
  stateStack.registerState<GameState>(States::ID::GAME);
  stateStack.registerState<GameOverState>(States::ID::GAME_OVER);
}
