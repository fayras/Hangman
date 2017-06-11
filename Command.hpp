#ifndef HANGMAN_COMMAND_HPP
#define HANGMAN_COMMAND_HPP

#include "Category.hpp"
#include <functional>

class SceneNode;

struct Command {
  Command();

  std::function<void(SceneNode&)> action;
  unsigned int category;
};

#endif //HANGMAN_COMMAND_HPP
