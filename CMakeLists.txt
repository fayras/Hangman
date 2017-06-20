cmake_minimum_required(VERSION 3.3)
project(Hangman)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Game.cpp Game.hpp Manikin.cpp Manikin.hpp Word.cpp Word.hpp Letter.cpp Letter.hpp LetterList.cpp LetterList.hpp SceneNode.cpp SceneNode.hpp Category.hpp SpriteNode.cpp SpriteNode.hpp Command.cpp Command.hpp CommandQueue.cpp CommandQueue.hpp ResourceIdentifiers.hpp ResourceHolder.hpp StateStack.hpp StateStack.cpp State.hpp State.cpp)
add_executable(Hangman ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML REQUIRED system window graphics audio)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(Hangman ${SFML_LIBRARIES})