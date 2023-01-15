#pragma once

#include "../primitives/size2d.hpp"

class Paddle;
class Ball;
class SDL_Renderer;

class Enemy {
public:
    Enemy(SDL_Renderer* renderer, const Size2D &screen, const Ball *ball, float speed);

    void render();
    void update(double delta);
    bool checkCollision(const Ball &ball);
    const Paddle *getPaddle() const;

private:
    Paddle *paddle;
    const Ball *ball;
    float speed;
    int randomness;
};
