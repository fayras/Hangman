#ifndef HANGMAN_MANIKIN_HPP
#define HANGMAN_MANIKIN_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <vector>
#include <memory>

class Manikin : public sf::Drawable, public sf::Transformable {
  public:
    Manikin();
    bool next();

  protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  private:
    std::vector<std::unique_ptr<sf::Shape>> parts;
    size_t attempts;
};

#endif //HANGMAN_MANIKIN_HPP
