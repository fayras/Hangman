#include <iostream>
#include "Game.hpp"
#include "GameState.hpp"
#include "TitleState.hpp"

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
    : window(sf::VideoMode(1000, 740), "Hangman"),
      isPaused(false),
      stateStack(State::Context(window, textures, fonts))
{
  window.setFramerateLimit(30);
  textures.load(Textures::ID::ALPHABET, "../assets/textures/alphabet.png");
  textures.load(Textures::ID::TITLE_BG, "../assets/textures/title_bg.jpg");

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
      if(!isPaused) {
        processEvents();
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
    stateStack.handleEvent(event);
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
}
