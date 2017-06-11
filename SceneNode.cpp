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
  return getWorldTransform() * sf::Vector2f();
}

sf::Transform SceneNode::getWorldTransform() const {
  sf::Transform transform = sf::Transform::Identity;

  for(const SceneNode* node = this; node != nullptr; node = node->parent) {
    transform = node->getTransform() * transform;
  }

  return transform;
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
  return Category::SCENE;
}

void SceneNode::update() {
  updateCurrent();
  updateChildren();
}

void SceneNode::updateCurrent() {
  // do nothing by default
}

void SceneNode::updateChildren() {
  for(Ptr& child : children) {
    child->update();
  }
}

void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= getTransform();

  drawCurrent(target, states);
  drawChildren(target, states);
}

void SceneNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
  // do nothing by default
}

void SceneNode::drawChildren(sf::RenderTarget &target, sf::RenderStates states) const {
  for(const Ptr& child : children) {
    child->draw(target, states);
  }
}
