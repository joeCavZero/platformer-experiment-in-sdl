#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "./../engine/entity/entity.hpp"
#include "./../engine/math/vector2.hpp"

class Player : public Entity {
    public:
        Player();
        ~Player();

        float speed = 2.0;

        void update();
        void draw(SDL_Renderer* renderer);
};

#endif