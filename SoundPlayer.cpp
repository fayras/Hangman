#include "SoundPlayer.hpp"
#include <SFML/Audio/Listener.hpp>
#include <cmath>

namespace {
  // Sound coordinate system, point of view of a player in front of the screen:
  // X = left; Y = up; Z = back (out of the screen)
  const float ListenerZ = 300.f;
  const float Attenuation = 8.f;
  const float MinDistance2D = 200.f;
  const float MinDistance3D = std::sqrt(MinDistance2D*MinDistance2D + ListenerZ*ListenerZ);
}

SoundPlayer::SoundPlayer()
  : soundBuffers(), sounds()
{
  soundBuffers.load(SoundEffect::GUESS_RIGHT,	"./assets/sounds/win.wav");
  soundBuffers.load(SoundEffect::GUESS_FAIL,	"./assets/sounds/fail.wav");
  soundBuffers.load(SoundEffect::SELECT,	"./assets/sounds/select.wav");
  soundBuffers.load(SoundEffect::FAIL,	"./assets/sounds/sad_trombone.wav");
  soundBuffers.load(SoundEffect::WIN,	"./assets/sounds/victory.wav");

  // Listener points towards the screen (default in SFML)
  sf::Listener::setDirection(0.f, 0.f, -1.f);
}

void SoundPlayer::play(SoundEffect::ID effect) {
  play(effect, getListenerPosition());
}

void SoundPlayer::play(SoundEffect::ID effect, sf::Vector2f position) {
  sounds.push_back(sf::Sound());
  sf::Sound& sound = sounds.back();

  sound.setBuffer(soundBuffers.get(effect));
  sound.setPosition(position.x, -position.y, 0.f);
  sound.setAttenuation(Attenuation);
  sound.setMinDistance(MinDistance3D);

  sound.play();
}

void SoundPlayer::removeStoppedSounds() {
  sounds.remove_if([] (const sf::Sound& s) {
    return s.getStatus() == sf::Sound::Stopped;
  });
}

void SoundPlayer::setListenerPosition(sf::Vector2f position) {
  sf::Listener::setPosition(position.x, -position.y, ListenerZ);
}

sf::Vector2f SoundPlayer::getListenerPosition() const {
  sf::Vector3f position = sf::Listener::getPosition();
  return sf::Vector2f(position.x, -position.y);
}
