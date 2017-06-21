#ifndef HANGMAN_COMPONENT_HPP
#define HANGMAN_COMPONENT_HPP

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <memory>

namespace sf {
  class Event;
}

namespace gui {
  class Component : public sf::Drawable, public sf::Transformable, private sf::NonCopyable {
    public:
      typedef std::shared_ptr<Component> Ptr;

      Component();
      ~Component();

      bool selected() const;
      virtual bool selectable() const = 0;
      virtual void select();
      virtual void deselect();

      bool active() const;
      virtual void activate();
      virtual void deactivate();

      virtual void handleEvent(const sf::Event& event) = 0;

    private:
      bool isSelected;
      bool isActive;

  };
}



#endif //HANGMAN_COMPONENT_HPP
