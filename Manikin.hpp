#ifndef HANGMAN_MANIKIN_HPP
#define HANGMAN_MANIKIN_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <vector>
#include <memory>
#include "SceneNode.hpp"

class Manikin : public SceneNode {
  public:
    Manikin();
    void next();
    bool alive() const;

  private:
    std::vector<std::unique_ptr<sf::Shape>> parts;
    size_t attempts;
};

#endif //HANGMAN_MANIKIN_HPP
