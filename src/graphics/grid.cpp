#include "grid.h"
#include <iostream>


void Grid::draw() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            SDL_Rect outline = {
                x * (CELL_WIDTH + zoom)+ x_offset,
                y * (CELL_HEIGHT + zoom)+ y_offset,
                CELL_WIDTH + zoom,
                CELL_HEIGHT + zoom

            };
            SDL_Rect cell = {
                x * (CELL_WIDTH + zoom) + 5 + x_offset,
                y * (CELL_HEIGHT + zoom) + 5 + y_offset,
                CELL_WIDTH - 10 + zoom,
                CELL_HEIGHT - 10 + zoom
            };

            SDL_RenderDrawRect(renderer, &outline);

            SDL_RenderFillRect(renderer, &cell);
        }
    }

    //y_offset += 5;
}

void Grid::on_key_event(SDL_Event &event) {
    if (event.type == SDL_KEYDOWN) {
        switch(event.key.keysym.sym) {
            case SDLK_RIGHT:
                x_offset += 5;
                break;
            case SDLK_LEFT:
                x_offset -= 5;
                break;
        }
    }

    if (event.motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) {
        if (abs(event.motion.xrel) > 25 || abs(event.motion.yrel) > 25) {
            return;
        }
        x_offset += event.motion.xrel;
        y_offset += event.motion.yrel;
    }
}
