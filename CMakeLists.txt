cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME "Hangman")
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
SET(CMAKE_INSTALL_RPATH "$ORIGIN/lib:$ORIGIN/")

# Set default build type explicitly to Release
if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE "Release")
endif (NOT CMAKE_BUILD_TYPE)

if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
    set(SFML_STATIC_LIBRARIES TRUE)
    find_package(SFML 2 REQUIRED COMPONENTS main)
endif ()

find_package(SFML 2 REQUIRED COMPONENTS audio graphics window system)
include_directories(${SFML_INCLUDE_DIR})

# Define sources and executable
set(SOURCE_FILES main.cpp Game.cpp Game.hpp Manikin.cpp Manikin.hpp Word.cpp Word.hpp Letter.cpp Letter.hpp SceneNode.cpp SceneNode.hpp Category.hpp SpriteNode.cpp SpriteNode.hpp Command.cpp Command.hpp CommandQueue.cpp CommandQueue.hpp ResourceIdentifiers.hpp ResourceHolder.hpp StateStack.hpp StateStack.cpp State.hpp State.cpp StateIdentifiers.hpp GameState.cpp GameState.hpp TitleState.cpp TitleState.hpp gui/Container.cpp gui/Container.hpp gui/Component.cpp gui/Component.hpp gui/Button.cpp gui/Button.hpp SoundPlayer.cpp SoundPlayer.hpp MusicPlayer.cpp MusicPlayer.hpp SoundNode.cpp SoundNode.hpp GameOverState.cpp GameOverState.hpp PauseState.cpp PauseState.hpp)

if(WIN32)
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets)

# Install target
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION "${CMAKE_SOURCE_DIR}/install")
install(DIRECTORY assets DESTINATION "${CMAKE_SOURCE_DIR}/install")
