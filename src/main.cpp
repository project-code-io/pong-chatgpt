#include <iostream>
#include <algorithm>

#include "engine/engine.hpp"

int main(int argc, char* argv[]) {
  const int screenWidth = 1200;
  const int screenHeight = 800;
  const bool fullscreen = false;

  const int display = 1;

  GameEngine *game = new GameEngine(
    "pong", 
    SDL_WINDOWPOS_CENTERED_DISPLAY(display),
    SDL_WINDOWPOS_CENTERED_DISPLAY(display),
    screenWidth, screenHeight, fullscreen
  );

  if (!game->init()) {
    std::cout << "failed to init game" << std::endl;
    return 1;
  }

  game->run();

  delete game;

  return 0;
}

