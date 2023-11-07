#include "grid.h"
#include <iostream>


void Grid::draw() const {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    for (int y = 0; y < 40; y++) {
        for (int x = 0; x < 40; x++) {
            SDL_Rect rect = {x * CELL_WIDTH, y * CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT};
            SDL_RenderDrawRect(renderer, &rect);
        }
    }
}