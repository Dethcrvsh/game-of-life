#include "grid.h"
#include <iostream>


Grid::Grid(SDL_Renderer* renderer, Board* board, int screen_width, int screen_height) :
ScreenEntity(renderer), board(board), screen_width(screen_width), screen_height(screen_height) {
    width = board->get_width();
    height = board->get_height();
}

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
                x * (CELL_WIDTH + zoom) + CELL_PADDING + x_offset,
                y * (CELL_HEIGHT + zoom) + CELL_PADDING + y_offset,
                CELL_WIDTH + zoom - 2 * CELL_PADDING,
                CELL_HEIGHT + zoom - 2 * CELL_PADDING
            };

            SDL_SetRenderDrawColor(renderer, OUTLINE_COLOR.r, OUTLINE_COLOR.g, OUTLINE_COLOR.b, OUTLINE_COLOR.a);
            SDL_RenderDrawRect(renderer, &outline);

            if (!board->is_cell_alive(x, y)) {
                continue;
            }

            SDL_SetRenderDrawColor(renderer, CELL_COLOR.r, CELL_COLOR.g, CELL_COLOR.b, CELL_COLOR.a);
            SDL_RenderFillRect(renderer, &cell);
        }
    }
}

Grid::Coordinates Grid::grid_to_board(const int x, const int y) const {
    return {
        (x - x_offset) / (CELL_WIDTH + zoom),
        (y - y_offset) / (CELL_HEIGHT + zoom)
    };
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

    // Bitmask out the correct mouse button
    if (event.motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) {
        if (abs(event.motion.xrel) < 25 && abs(event.motion.yrel) < 25) {
            x_offset += event.motion.xrel;
            y_offset += event.motion.yrel;
        }
    }

    if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
        // Get mouse coordinates
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        Coordinates c = grid_to_board(mouseX, mouseY);

        board->toggle_cell(c.x, c.y);
    }

    if (event.type == SDL_MOUSEWHEEL) {
        zoom += event.wheel.y * ZOOM_SENSITIVITY;
    }
}
