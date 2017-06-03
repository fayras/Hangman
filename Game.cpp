#include <iostream>
#include "Game.hpp"

Game::Game()
    : window(sf::VideoMode(1000, 740), "Hangman"),
      isPaused(false),
      word("Test abc")
{
  window.setFramerateLimit(30);
  manikin.move(15, 600);
  word.move(500, 200);
  letters.move(500, 400);
}

void Game::run() {
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  while (window.isOpen()) {
    if(!isPaused) {
      processEvents();
    }
    render();
  }
}

void Game::processEvents() {
  sf::Event event;
  while (window.pollEvent(event)) {
    //letters.handleEvent(event);
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

void Game::render() {
  window.clear();

  window.draw(manikin);
  window.draw(word);
  window.draw(letters);

  window.setView(window.getDefaultView());
  window.display();
}

void Game::guess(char ch) {
  // Already guessed a char -> do nothing.
  if(std::find(guesses.begin(), guesses.end(), ch) != guesses.end()) {
    return;
  }

  guesses.push_back(ch);
  if(word.exists(ch)) {
    manikin.next();
    if(!manikin.alive()) {
      std::cout << "you lose" << std::endl;
    }
  } else {
    word.reveal(ch);
    if(word.finished()) {
      std::cout << "you won" << std::endl;
    }
  }
}
