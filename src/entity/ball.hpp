#pragma once

#include <SDL2/SDL.h>
#include "../primitives/vector2d.hpp"
#include "../primitives/size2d.hpp"

class Paddle;

class Ball {
public:
    Ball(SDL_Renderer* renderer, Size2D screen, float radius);
    void update(double delta);
    void render();
    void reset();

    Vector2D getPosition() const;
    float getRadius() const;

    void bounceOffPaddle(const Paddle *paddle);

private:
    Vector2D position;
    Vector2D velocity;
    Size2D screen;
    float radius;
    SDL_Renderer* renderer;

    void addRandomSpeed();
};
