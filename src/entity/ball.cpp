#include "ball.hpp"

#include <SDL2/SDL2_gfxPrimitives.h>
#include <iostream>
#include "paddle.hpp"

Ball::Ball(
  SDL_Renderer* renderer, Size2D screen, float radius
) : screen(screen), renderer(renderer), radius(radius) {
  this->reset();
}

float randomSpeed() {
  const float speed = 500 + rand() % 400;
  const int inverse = rand() % 2;
  if (inverse) {
    return -speed;
  }
  return speed;
}

void Ball::reset() {
  position.x = float(screen.width) / 2;
  position.y = float(screen.height) / 2;

  velocity.x = randomSpeed();
  velocity.y = randomSpeed();
}

void Ball::update(double delta) {
  position = position + velocity * delta;

  // Check for collision with left and right sides of screen
  if (position.x + radius < 0) {
    this->reset();
  }

  if (position.x - radius > screen.width) {
    this->reset();
  }

  // Check for collision with top and bottom of screen
  if (position.y - radius < 0) {
    position.y = radius;
    velocity.y = -velocity.y;
    addRandomSpeed();
  }

  if (position.y + radius > screen.height) {
    position.y = screen.height - radius;
    velocity.y = -velocity.y;
    addRandomSpeed();
  }
}

void Ball::render() {
  int x = static_cast<int>(position.x);
  int y = static_cast<int>(position.y);
  int diameter = static_cast<int>(2 * radius);
  filledCircleRGBA(renderer, x, y, radius, 255, 255, 255, 255);
}

Vector2D Ball::getPosition() const {
  return this->position;
}

float Ball::getRadius() const {
  return this->radius;
}

void Ball::bounceOffPaddle(const Paddle *paddle) {
  int x = paddle->getLeft() - radius; 

  if (velocity.x < 0) {
    x = paddle->getRight() + radius;
  }

  position.x = x;

  velocity.x = -velocity.x;

  addRandomSpeed();
}

void Ball::addRandomSpeed() {
  float randomX = rand() % 20;
  float randomY = rand() % 20;

  if (velocity.x > 0) {
    velocity.x += randomX;
  } else {
    velocity.x -= randomX;
  }

  if (velocity.y > 0) {
    velocity.y += randomY;
  } else {
    velocity.y -= randomY;
  }

}
