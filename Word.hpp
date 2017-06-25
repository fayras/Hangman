#ifndef HANGMAN_WORD_HPP
#define HANGMAN_WORD_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include "SceneNode.hpp"

class Word : public SceneNode {
  public:
    Word(std::string word, const sf::Font& font);
    bool guess(char ch);
    bool finished() const;

  protected:
    void updateCurrent(sf::Time dt, CommandQueue &commands) override;
    void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const override;

  public:
    unsigned int getCategory() const override;

  private:
    bool exists(char ch);
    void reveal(char ch);

    std::string word;
    std::string orgWord;
    std::vector<size_t> revealed;
    std::vector<char> guesses;
    const sf::Font& font;
};

#endif //HANGMAN_WORD_HPP
