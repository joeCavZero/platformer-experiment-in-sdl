#include "player.hpp"
#include "settings.hpp"
#include "SDL.h"

Player::Player() {
    this->position = Vector2f(0,0);
    this->size = Sizef(32,32);
    this->velocity = Vector2f(0,0);
    this->texture = nullptr;
}

Player::~Player() {}



void Player::update() {
    const Uint8* key_state = SDL_GetKeyboardState(NULL);

    if( key_state[SDL_SCANCODE_D] ) {
        this->velocity.x = this->speed;
    } else if( key_state[SDL_SCANCODE_A] ) {
        this->velocity.x = -this->speed;
    } else {
        this->velocity.x = 0;
    }

    if( key_state[SDL_SCANCODE_W] ) {
        velocity.y = -4.0;
    }

    this->velocity.y += 0.1;

    this->position.x += this->velocity.x;
    this->position.y += this->velocity.y;

    if( position.y+size.height > CANVAS_HEIGHT ) {
        position.y = CANVAS_HEIGHT-size.height;
        velocity.y = 0;
    }


}

void Player::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor( renderer, 0,255,0,255 );
    SDL_FRect rect = {
        this->position.x,
        this->position.y,
        this->size.width,
        this->size.height
    };
    
    SDL_RenderFillRectF(renderer, &rect);

}