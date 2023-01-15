#pragma once

#include <SDL2/SDL.h>
#include "../primitives/size2d.hpp"

class Ball;
class Player;
class Enemy;
class Timer;

class GameEngine {
public:
    GameEngine(
      const char* title, int xpos, int ypos, int width, int height, bool fullscreen
    );
    ~GameEngine();

    bool init();
    void run();

private:
    bool running;
    SDL_Window* window;
    SDL_Renderer* renderer;
    Player *player;
    Ball *ball;
    Enemy *enemy;
    Timer *timer;

    const char *title;
    int xpos;
    int ypos;
    Size2D screenSize;
    bool fullscreen;

    void update(Uint64 ticks);
    void render();
    void handleEvents();
};

