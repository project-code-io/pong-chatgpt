#pragma once

#include <SDL2/SDL.h>

class Timer {
public:
    Timer();

    void start();
    void stop();
    void pause();
    void unpause();
    Uint64 getTicks();
    bool isStarted();
    bool isPaused();

private:
    Uint64 startTicks;
    Uint64 pausedTicks;
    bool paused;
    bool started;

};

