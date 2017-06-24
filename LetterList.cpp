#include "LetterList.hpp"
#include "Letter.hpp"
#include "ResourceHolder.hpp"
#include "Word.hpp"

const int CHARS_PER_ROW = 7;
const int TEXTURE_SIZE = 40;
const int TEXTURE_OFFSET_TO_A = 1320;

LetterList::LetterList(State::Context context, CommandQueue& commandQueue)
  : Container()
{
  int counter = 0;
  for(int c = 97; c <= 122; c++) {
    std::unique_ptr<Letter> l(new Letter(static_cast<char>(c), context, sf::IntRect(
        TEXTURE_OFFSET_TO_A + (c - 97) * TEXTURE_SIZE, 0, TEXTURE_SIZE, TEXTURE_SIZE
    )));
    l->setCallback([this, c, &commandQueue] () {
      Command command;
      command.category = Category::GUESS;
      command.action = derivedAction<Word>([this, c] (Word& node, sf::Time) {
        node.guess(static_cast<char>(c));
      });
      commandQueue.push(command);
    });
    if(counter >= CHARS_PER_ROW) {
      counter = 0;
    }
    l->move(counter++ * 60, (c - 97) / CHARS_PER_ROW * 50);
    pack(std::move(l));
  }
}
