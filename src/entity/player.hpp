#pragma once

#include <SDL2/SDL.h>
#include "../primitives/size2d.hpp"

class Paddle;
class Ball;

class Player {
public:
  Player(SDL_Renderer* renderer, const Size2D &screen);
  ~Player();

  bool checkCollision(const Ball &ball);
  void update(double delta, const Uint8 *keystate);
  void render();
  const Paddle *getPaddle() const;

private:
  Paddle *paddle;
};
