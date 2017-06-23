#ifndef HANGMAN_BUTTON_HPP
#define HANGMAN_BUTTON_HPP

#include "Component.hpp"
#include "../ResourceIdentifiers.hpp"
#include "../ResourceHolder.hpp"
#include "../State.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <vector>
#include <string>
#include <memory>
#include <functional>

namespace gui {
  class Button : public Component {
    public:
      typedef std::shared_ptr<Button> Ptr;
      typedef std::function<void()> Callback;

      Button(State::Context context);
      void setCallback(Callback callback);
      void setText(const std::string& text);
      void setToggle(bool flag);

      virtual bool selectable() const;
      virtual void select();
      virtual void deselect();

      virtual void activate();
      virtual void deactivate();
      virtual void handleEvent(const sf::Event& event);
      virtual sf::FloatRect getBounds() const override ;

    protected:
      virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

      Callback callback;
      sf::Texture& normalTexture;
      sf::Texture& selectedTexture;
      sf::Texture& pressedTexture;
      sf::Sprite sprite;
      sf::Text text;
      bool isToggle;
  };
}

#endif //HANGMAN_BUTTON_HPP
