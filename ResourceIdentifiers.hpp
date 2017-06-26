#ifndef HANGMAN_RESOURCEIDENTIFIERS_HPP
#define HANGMAN_RESOURCEIDENTIFIERS_HPP

// Forward declaration of SFML classes
namespace sf {
  class Texture;
  class Font;
  class Shader;
  class SoundBuffer;
}

namespace Textures {
  enum ID {
    ALPHABET,
    MANIKIN,
    TITLE_BG,
    GAME_BG,
    BUTTON_NORMAL,
    BUTTON_SELECTED,
    BUTTON_PRESSED
  };
}

namespace Fonts {
  enum ID {
    MAIN,
  };
}

namespace SoundEffect {
  enum ID {
    GUESS_RIGHT,
    GUESS_FAIL,
    SELECT
  };
}

namespace Music {
  enum ID {
    TITLE,
    GAME,
    WIN,
    LOSE,
    GUESS
  };
}


// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID>	TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;
typedef ResourceHolder<sf::SoundBuffer, SoundEffect::ID> SoundBufferHolder;

#endif //HANGMAN_RESOURCEIDENTIFIERS_HPP
