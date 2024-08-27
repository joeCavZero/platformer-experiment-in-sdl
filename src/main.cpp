#define SDL_MAIN_HANDLED

#include <iostream>
#include "SDL.h"
#include "engine/engine.hpp"

int main( void ) {
    
    Engine engine = Engine();
    engine.run();

    return 0;
}