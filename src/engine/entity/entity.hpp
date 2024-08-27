#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "engine/math/vector2.hpp"
#include "engine/math/size.hpp"

#include "SDL.h"
class Entity {
    public:
        Vector2f position;
        Sizef size;
        Vector2f velocity;
        SDL_Texture* texture;

        Entity();
        ~Entity();

        virtual void update();
        virtual void draw(SDL_Renderer* renderer);
        
};

#endif