cmake_minimum_required(VERSION 3.3)
project(Hangman)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Game.cpp Game.hpp Manikin.cpp Manikin.hpp Word.cpp Word.hpp)
add_executable(Hangman ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(Hangman ${SFML_LIBRARIES})