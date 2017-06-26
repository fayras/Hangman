#ifndef HANGMAN_MANIKIN_HPP
#define HANGMAN_MANIKIN_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <vector>
#include <memory>
#include "SpriteNode.hpp"

class Manikin : public SpriteNode {
  public:
    Manikin(const sf::Texture& texture);
    unsigned int getCategory() const override;
    void advance();
    bool dead() const;

  protected:
    void updateCurrent(sf::Time dt, CommandQueue &commands) override;

  private:
    unsigned int maxAttempts;
    unsigned int attempts;
};

#endif //HANGMAN_MANIKIN_HPP
