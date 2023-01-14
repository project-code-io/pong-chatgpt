#include "paddle.hpp"

Paddle::Paddle(
  SDL_Renderer* renderer, Vector2D position, Size2D screen, Size2D size
) : position(position), screen(screen), size(size), renderer(renderer) {}

void Paddle::render() {
  SDL_Rect rect;
  rect.x = static_cast<int>(position.x);
  rect.y = static_cast<int>(position.y);
  rect.w = static_cast<int>(size.width);
  rect.h = static_cast<int>(size.height);
  SDL_RenderFillRect(renderer, &rect);
}

bool Paddle::checkCollision(const Ball& ball) {
  Vector2D bpos = ball.getPosition();
  float bx = bpos.x;
  float by = bpos.y;
  float br = ball.getRadius();

  if (bx + br >= position.x && bx - br <= position.x + size.width
      && by + br >= position.y && by - br <= position.y + size.height) {
    return true;
  }

  return false;
}

void Paddle::moveUp(float distance) {
  if (position.y - distance > 0) {
    position.y -= distance;
  } else {
    position.y = 0;
  }
}

void Paddle::moveDown(float distance) {
  if (position.y + distance + size.height < screen.height) {
    position.y += distance;
  } else {
    position.y = screen.height - size.height;
  }
}

double Paddle::getRight() const {
  return this->position.x + this->size.width;
}

double Paddle::getLeft() const {
  return this->position.x;
}
