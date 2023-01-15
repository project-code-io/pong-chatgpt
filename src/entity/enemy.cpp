#include "enemy.hpp"
#include "ball.hpp"
#include "paddle.hpp"
#include "../primitives/vector2d.hpp"

Enemy::Enemy(
  SDL_Renderer* renderer, const Size2D &screen, const Ball *ball, float speed
) : paddle(nullptr), ball(ball), speed(speed) {
  Size2D size;
  size.width = screen.width * 0.025;
  size.height = screen.height * 0.1;

  Vector2D position = Vector2D(
    screen.width - size.width * 2, 
    float(screen.height) / 2 - float(size.height) / 2
  );

  randomness = size.height * 1.2;

  paddle = new Paddle(renderer, position, screen, size);
}

void Enemy::render() {
  paddle->render();
}

double randomNumber(int randomness) {
  return double((rand() % randomness) - randomness / 2);
}

void Enemy::update(double delta) {
  Vector2D ballPosition = ball->getPosition();

  if (ballPosition.y + randomNumber(randomness) < paddle->getMiddle()) {
    paddle->moveUp(speed * delta);
  }

  else if (ballPosition.y + randomNumber(randomness) >  paddle->getMiddle()) {
    paddle->moveDown(speed * delta);
  }
}

bool Enemy::checkCollision(const Ball &ball) {
  return paddle->checkCollision(ball);
}

const Paddle *Enemy::getPaddle() const {
  return paddle;
}
