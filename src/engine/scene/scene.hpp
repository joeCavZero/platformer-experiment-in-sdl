#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "./../entity/entity.hpp"

class Scene {
    public:
        Scene();
        ~Scene();

        std::vector<Entity*> entities;

        void addEntity(Entity* entity);

        void process();
        void render(SDL_Renderer* renderer);
};

#endif