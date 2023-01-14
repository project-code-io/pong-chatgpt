#include "timer.hpp"

Timer::Timer() : startTicks(0), pausedTicks(0), paused(false), started(false) {}

void Timer::start() {
  started = true;
  paused = false;
  startTicks = SDL_GetTicks64();
}

void Timer::stop() {
  started = false;
  paused = false;
}

void Timer::pause() {
  if (started && !paused) {
    paused = true;
    pausedTicks = SDL_GetTicks64() - startTicks;
  }
}

void Timer::unpause() {
  if (paused) {
    paused = false;
    startTicks = SDL_GetTicks64() - pausedTicks;
    pausedTicks = 0;
  }
}

Uint64 Timer::getTicks() {
  Uint64 time = 0;
  if (started) {
    if (paused) {
      time = pausedTicks;
    } else {
      time = SDL_GetTicks64() - startTicks;
    }
  }
  return time;
}

bool Timer::isStarted() {
  return started;
}

bool Timer::isPaused() {
  return paused;
}
