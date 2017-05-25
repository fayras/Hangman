#ifndef HANGMAN_WORD_HPP
#define HANGMAN_WORD_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Transformable.hpp>

class Word : public sf::Drawable, public sf::Transformable {
  public:
    Word(const std::string &word);
    bool exists(char ch);
    void reveal(char ch);

  protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  private:
    std::string word;
    std::vector<size_t> revealed;
    sf::Font font;
};

#endif //HANGMAN_WORD_HPP
