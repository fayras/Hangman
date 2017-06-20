#ifndef HANGMAN_WORD_HPP
#define HANGMAN_WORD_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include "SceneNode.hpp"

class Word : public SceneNode {
  public:
    Word(std::string word);
    bool exists(char ch);
    void reveal(char ch);
    bool finished() const;

  protected:
    void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const override;

  private:
    std::string word;
    std::string orgWord;
    std::vector<size_t> revealed;
    sf::Font font;
};

#endif //HANGMAN_WORD_HPP
