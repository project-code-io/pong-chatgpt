#include <SDL2/SDL.h>

class GameEngine {
public:
    GameEngine(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    ~GameEngine();

    bool init();
    void run();

private:
    bool running;
    SDL_Window* window;
    SDL_Renderer* renderer;

    const char *title;
    int xpos;
    int ypos;
    int width;
    int height; 
    bool fullscreen;

    void update();
    void render();
    void handleEvents();
};

