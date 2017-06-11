#include "SceneNode.hpp"

#include "Command.hpp"
#include <algorithm>
#include <cassert>

SceneNode::SceneNode()
  : children(), parent(nullptr)
{}

void SceneNode::attachChild(SceneNode::Ptr child) {
  child->parent = this;
  children.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode &node) {
  auto found = std::find_if(children.begin(), children.end(), [&] (Ptr& p) {
    return p.get() == &node;
  });

  assert(found != children.end());

  Ptr result = std::move(*found);
  result->parent = nullptr;
  children.erase(found);
  return result;
}

sf::Vector2f SceneNode::getWorldPosition() const {
  return sf::Vector2f();
}

sf::Transform SceneNode::getWorldTransform() const {
  return sf::Transform();
}

void SceneNode::onCommand(const Command &command) {
  if(command.category & getCategory()) {
    command.action(*this);
  }

  for(Ptr& child : children) {
    child->onCommand(command);
  }
}

unsigned int SceneNode::getCategory() const {
  return 0;
}

void SceneNode::updateCurrent() {

}

void SceneNode::updateChildren() {

}

void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}

void SceneNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {

}

void SceneNode::drawChildren(sf::RenderTarget &target, sf::RenderStates states) const {

}
