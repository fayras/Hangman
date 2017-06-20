#ifndef HANGMAN_STATESTACK_HPP
#define HANGMAN_STATESTACK_HPP

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>

#include <vector>
#include <utility>
#include <functional>
#include <map>

namespace sf {
  class Event;
  class RenderWindow;
}

class StateStack : private sf::NonCopyable {
  public:
    enum Action {
      PUSH, POP, CLEAR
    };

    explicit StateStack(State::Context context);

    void update(sf::Time dt);
    void draw() const;
    void handleEvent(const sf::event& event);

    template<typename T>
    void registerState(States::ID stateID);
    void push(States::ID stateID);
    void pop();
    void clear();

    bool empty() const;

  private:
    struct PendingChange {
      explicit PendingChange(Action action, States::ID stateID = States::NONE);
      Action action;
      States::ID stateID;      
    };

    State::Ptr createState(States::ID stateID);
    void applyPendingChanges();

    std::vector<State::Ptr> stack;
    std::vector<PendingChange> pendingList;

    State::Context context;
    std::map<States::ID, std::function<State::Ptr()>> factory;
};

template <typename T>
void StateStack::registerState(States::ID id) {
  factory[id] = [this] () {
    return State::Ptr(new T(*this, context));
  }
}

#endif //HANGMAN_STATESTACK_HPP