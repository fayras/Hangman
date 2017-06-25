#ifndef HANGMAN_MUSICPLAYER_HPP
#define HANGMAN_MUSICPLAYER_HPP

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Audio/Music.hpp>

#include <map>
#include <string>

class MusicPlayer : private sf::NonCopyable {
  public:
    MusicPlayer();
    void play(Music::ID theme);
    void stop();
    void setPaused(bool paused);
    void setVolume(float volume);

  private:
    sf::Music music;
    std::map<Music::ID, std::string> filenames;
    float volume;
};


#endif //HANGMAN_MUSICPLAYER_HPP
