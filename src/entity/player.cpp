#include "player.hpp"
#include "paddle.hpp"
#include "ball.hpp"

Player::Player(
  SDL_Renderer *renderer, const Size2D &screen
) : paddle(nullptr) {

  Size2D size;
  size.width = screen.width * 0.025;
  size.height = screen.height * 0.1;

  Vector2D position = Vector2D(
    size.width * 2, 
    float(screen.height) / 2 - float(size.height) / 2
  );

  paddle = new Paddle(renderer, position, screen, size);
}

Player::~Player() {
  delete paddle;
}

bool Player::checkCollision(const Ball &ball) {
  return paddle->checkCollision(ball);
}

void Player::update(double delta, const Uint8 *keystate) {
  const double speed = 600.0f;

  if (keystate[SDL_SCANCODE_W]) {
    paddle->moveUp(speed * delta);
  }
  if (keystate[SDL_SCANCODE_S]) {
    paddle->moveDown(speed * delta);
  }
}

void Player::render() {
  paddle->render();
}

const Paddle *Player::getPaddle() const {
  return paddle;
}
