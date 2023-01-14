#include "engine.hpp"
#include "../entity/ball.hpp"
#include "../entity/player.hpp"
#include "../timer/timer.hpp"

GameEngine::GameEngine(
  const char* title, int xpos, int ypos, int width, int height, bool fullscreen
) : running(false), window(nullptr), renderer(nullptr), 
  player(nullptr), ball(nullptr), timer(nullptr), title(title),
  xpos(xpos), ypos(ypos), screenSize(width, height) {}

GameEngine::~GameEngine() {
  delete player;
  delete ball;
  delete timer;

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

  window = SDL_CreateWindow(
    title, xpos, ypos, screenSize.width, screenSize.height, flags
  );
  if (!window) {
    return false;
  }
  //
  // Create a renderer
  renderer = SDL_CreateRenderer(window, -1, 0);
  if (!renderer) {
    return false;
  }

  player = new Player(renderer, screenSize);
  ball = new Ball(renderer, screenSize, 15);
  timer = new Timer();

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

const int FRAME_RATE = 60;
const int FRAME_TIME = 1000 / FRAME_RATE;

void GameEngine::run() {
  Uint64 frameStart, lastTick = 0;
  running = true;

  while (running) {
    this->timer->start();
    this->handleEvents();
    this->update(lastTick);
    this->render();

    if (this->timer->getTicks() < FRAME_TIME) {
      SDL_Delay(FRAME_TIME - this->timer->getTicks());
    }

    lastTick = this->timer->getTicks();
  }
}

void GameEngine::update(Uint64 ticks) {
  const float delta = ticks / 1000.0f;
  // Do any updates here
  ball->update(delta);
  player->update(delta, SDL_GetKeyboardState(NULL));

  if (player->checkCollision(*ball)) {
    ball->bounceOffPaddle(player->getPaddle());
  }
}

void GameEngine::render() {
  // Clear the screen
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  // Draw any graphics here
  ball->render();
  player->render();

  // Render the screen
  SDL_RenderPresent(renderer);
}
