cmake_minimum_required(VERSION 3.0)
project(Hangman)

if (CMAKE_VERSION VERSION_LESS "3.1")
  if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set (CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")
  endif ()
else ()
  set (CMAKE_CXX_STANDARD 11)
endif ()

set(SOURCE_FILES main.cpp Game.cpp Game.hpp Manikin.cpp Manikin.hpp Word.cpp Word.hpp Letter.cpp Letter.hpp LetterList.cpp LetterList.hpp SceneNode.cpp SceneNode.hpp Category.hpp SpriteNode.cpp SpriteNode.hpp Command.cpp Command.hpp CommandQueue.cpp CommandQueue.hpp ResourceIdentifiers.hpp ResourceHolder.hpp StateStack.hpp StateStack.cpp State.hpp State.cpp StateIdentifiers.hpp GameState.cpp GameState.hpp TitleState.cpp TitleState.hpp)
add_executable(Hangman ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML REQUIRED system window graphics audio)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(Hangman ${SFML_LIBRARIES})