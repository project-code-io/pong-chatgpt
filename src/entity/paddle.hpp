#pragma once

#include <SDL2/SDL.h>
#include "../primitives/vector2d.hpp"
#include "../primitives/size2d.hpp"
#include "ball.hpp"

class Paddle {
public:
  Paddle(SDL_Renderer* renderer, Vector2D position, Size2D screen, Size2D size);

  void render();
  bool checkCollision(const Ball& ball);
  void moveUp(float distance);
  void moveDown(float distance);

  double getRight() const;
  double getLeft() const;
  double getTop() const;
  double getBottom() const;
  double getMiddle() const;

private:
    Vector2D position;
    Size2D size;
    Size2D screen;
    SDL_Renderer* renderer;
};

