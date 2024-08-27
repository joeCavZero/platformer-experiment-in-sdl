#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "SDL.h"
#include <vector>
#include "entity/entity.hpp"
#include "scene/scene.hpp"

class Engine {
    public:
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Texture* canvas;
        Scene scene;

        bool isRunning = false;

        Engine();
        ~Engine();

        void run();
    
    private:
        void handleEvents();
        void process();
        void render();
        void close();

        void renderCanvas();
};

#endif