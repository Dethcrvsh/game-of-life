#pragma once

#include <SDL.h>
#include <iostream>


/**
 * @class ScreenEntity
 * @brief Interface of an entity that should have a graphic representation.
 * 
 */
class ScreenEntity {
public:
    ScreenEntity(SDL_Renderer* renderer) : renderer(renderer) {};

    virtual void draw() const = 0;

protected:
    SDL_Renderer* renderer;
};