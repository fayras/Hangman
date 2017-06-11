#ifndef HANGMAN_SCENENODE_HPP
#define HANGMAN_SCENENODE_HPP

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <vector>
#include <memory>

#include "Category.hpp"

struct Command;

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable {
  public:
    typedef std::unique_ptr<SceneNode> Ptr;

    SceneNode();

    void attachChild(Ptr child);
    Ptr detachChild(const SceneNode& node);

    sf::Vector2f getWorldPosition() const;
    sf::Transform getWorldTransform() const;

    void onCommand(const Command& command);
    virtual unsigned int getCategory() const;

  private:
    virtual void updateCurrent();
    void updateChildren();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

    std::vector<Ptr> children;
    SceneNode* parent;
};


#endif //HANGMAN_SCENENODE_HPP
