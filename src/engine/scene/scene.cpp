#include "scene.hpp"
#include "SDL.h"

Scene::Scene() {
    this->entities = std::vector<Entity*>();
}

Scene::~Scene() {}

void Scene::addEntity(Entity* entity) {
    this->entities.push_back(entity);
}
void Scene::process() {

    for( auto entity : this->entities ) {
        entity->update();
    }

}


void Scene::render(SDL_Renderer* renderer) {
    for( auto entity : this->entities ) {
        entity->draw(renderer);
    }
}