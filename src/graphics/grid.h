#pragma once

#include "screen_entity.h"


class Grid : public ScreenEntity {
public:
    Grid(SDL_Renderer* renderer) : ScreenEntity(renderer) {};

    void draw() const override;

private:
    static const int CELL_WIDTH = 25;
    static const int CELL_HEIGHT = 25;
};