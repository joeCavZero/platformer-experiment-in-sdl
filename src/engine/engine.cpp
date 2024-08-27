
#include "engine.hpp"
#include "SDL.h"
#include "./../settings.hpp"
#include "scene/scene.hpp"
#include "entities/player.hpp"

Engine::Engine() {
    if( SDL_Init( SDL_INIT_EVERYTHING) != 0 ) {
        SDL_Log( SDL_GetError() );
    }

    this->window = SDL_CreateWindow(
        "hey",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        CANVAS_WIDTH, CANVAS_HEIGHT,
        SDL_WINDOW_RESIZABLE
    );
    if( window == nullptr ) {
        SDL_Log( "%s", SDL_GetError() );
    }
    this->renderer = SDL_CreateRenderer( 
        window, 
        -1, 
        0 
    );
    if( renderer == nullptr ) {
        SDL_Log( "%S", SDL_GetError );
    }

    this->canvas = SDL_CreateTexture(
        this->renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_TARGET,
        CANVAS_WIDTH,
        CANVAS_HEIGHT
    );
    this->scene = Scene();
    this->isRunning = false;
}

Engine::~Engine() {}


void Engine::run() {
    this->isRunning = true;
    Player player = Player();
    scene.addEntity( &player );

    while( isRunning ) {
        auto first_tick = SDL_GetTicks();


        this->handleEvents();
        this->process();
        this->render();


        auto elapsed_time = SDL_GetTicks() - first_tick;
        if(elapsed_time < TICKS_PER_FRAME) {
            SDL_Delay( TICKS_PER_FRAME - elapsed_time );
        }
    }

    this->close();
}

void Engine::handleEvents() {
    SDL_Event event;
    while( SDL_PollEvent(&event) ) {
        if( event.type == SDL_QUIT ) {
            this->isRunning = false;
        }
    }
}

void Engine::process() {
    this->scene.process();
}

void Engine::render() {
    SDL_SetRenderDrawColor(renderer, 0,0,0,255 );
    SDL_RenderClear(renderer);

    SDL_SetRenderTarget( this->renderer, this->canvas );
    {
        SDL_SetRenderDrawColor( this->renderer, 0,255,255,255 );
        SDL_RenderClear(this->renderer);
        {
            this->scene.render( this->renderer );
        }
        
    }
    SDL_SetRenderTarget( this->renderer, nullptr );
    this->renderCanvas();
        //SDL_RenderCopy( this->renderer, this->canvas, nullptr, nullptr );
    SDL_RenderPresent(renderer);
}

void Engine::renderCanvas() {
    SDL_Surface* win_sur = SDL_GetWindowSurface(this->window);
    int win_width = win_sur->w;
    int win_height = win_sur->h;

    float delta_x = win_width / static_cast<float>(CANVAS_WIDTH);
    float delta_y = win_height / static_cast<float>(CANVAS_HEIGHT);

    float scale = 1.0;
    
    if( delta_x < delta_y ) {
        scale = delta_x;
    } else {
        scale = delta_y;
    }


    int diff_x = win_width - (CANVAS_WIDTH * scale);
    int diff_y = win_height - (CANVAS_HEIGHT * scale);

    SDL_Rect aux_rect = {
        diff_x / 2,
        diff_y / 2,
        static_cast<int>( CANVAS_WIDTH * scale ),
        static_cast<int>( CANVAS_HEIGHT * scale )
    };

    SDL_RenderCopy(
        this->renderer,
        this->canvas,
        nullptr,
        &aux_rect
    );
}

void Engine::close() {
    SDL_DestroyRenderer( this->renderer );
    SDL_DestroyWindow( this->window );
    SDL_Quit();
}

