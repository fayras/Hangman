#ifndef HANGMAN_BUTTON_HPP
#define HANGMAN_BUTTON_HPP

#include "Component.hpp"
#include "../ResourceIdentifiers.hpp"
#include "../ResourceHolder.hpp"

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

      Button(const FontHolder& fonts, const TextureHolder& textures);
      void setCallback(Callback callback);
      void setText(const std::string& text);
      void setToggle(bool flag);

      virtual bool selectable() const;
      virtual void select();
      virtual void deselect();

      virtual void activate();
      virtual void deactivate();
      virtual void handleEvent(const sf::Event& event);

    private:
      virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

      Callback callback;
      const sf::Texture& normalTexture;
      const sf::Texture& selectedTexture;
      const sf::Texture& pressedTexture;
      sf::Sprite sprite;
      sf::Text text;
      bool isToggle;
  };
}

#endif //HANGMAN_BUTTON_HPP
