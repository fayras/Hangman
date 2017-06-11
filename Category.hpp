#ifndef HANGMAN_CATEGORY_HPP
#define HANGMAN_CATEGORY_HPP

namespace Category {
  enum Type {
    NONE = 0,
    SCENE = 1 << 0,
    LETTER = 1 << 1,
    MANIKIN = 1 << 2
  };
}

#endif //HANGMAN_CATEGORY_HPP
