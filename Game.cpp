#include <iostream>
#include "Game.hpp"

sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
    : window(sf::VideoMode(1000, 740), "Hangman"),
      isPaused(false),
      word("test")
{
  window.setFramerateLimit(30);
  manikin.move(100, 100);
}

void Game::run() {
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  while (window.isOpen()) {
    processEvents();
    timeSinceLastUpdate += clock.restart();
    while (timeSinceLastUpdate > TimePerFrame) {
      timeSinceLastUpdate -= TimePerFrame;
      processEvents();
      if(!isPaused) {
        update(TimePerFrame);
      }
    }
    render();
  }
}

void Game::processEvents() {
  sf::Event event;
  while (window.pollEvent(event)) {
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
      case sf::Event::TextEntered:
        guess(static_cast<char>(event.text.unicode));
      default:
        break;
    }
  }
}

void Game::update(sf::Time dt) {
  // update
}

void Game::render() {
  window.clear();

  window.draw(manikin);
  window.draw(word);

  window.setView(window.getDefaultView());
  window.display();
}

void Game::guess(char ch) {
  guesses.push_back(ch);
  if(word.exists(ch)) {
    if(!manikin.next()) {
      std::cout << "you lose" << std::endl;
    }
  } else {
    word.reveal(ch);
  }
}
