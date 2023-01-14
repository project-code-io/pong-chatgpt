#include "engine.hpp"

GameEngine::GameEngine(
  const char* title, int xpos, int ypos, int width, int height, bool fullscreen
) : running(false), window(nullptr), renderer(nullptr), title(title),
  xpos(xpos), ypos(ypos), width(width), height(height) {}

GameEngine::~GameEngine() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

bool GameEngine::init() {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    return false;
  }
  
  // Create a window
  int flags = 0;
  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }
  window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
  if (!window) {
    return false;
  }
  //
  // Create a renderer
  renderer = SDL_CreateRenderer(window, -1, 0);
  if (!renderer) {
    return false;
  }

  // Set the background color to white
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

  return true;
}

void GameEngine::handleEvents() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        running = false;
        break;
      default:
        break;
    }
  }
}

void GameEngine::run() {
  running = true;

  while (running) {
    this->handleEvents();
    this->update();
    this->render();
  }
}

void GameEngine::update() {
  // Do any updates here
}

void GameEngine::render() {
  // Clear the screen
  SDL_RenderClear(renderer);
  // Draw any graphics here
  SDL_RenderPresent(renderer);
}
