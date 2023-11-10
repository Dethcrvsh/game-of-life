#include "graphics_handler.h"
#include "grid.h"
#include "screen_entity.h"
#include "../key_listener.h"

GraphicsHandler::GraphicsHandler(Board* board) {
    SDL_Init(SDL_INIT_EVERYTHING);    

    window = SDL_CreateWindow(
        WINDOW_TITLE,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Grid* grid = new Grid(renderer, board, WINDOW_WIDTH, WINDOW_HEIGHT);
    screen_entities.push_back(grid);
    KeyListener::register_listener(grid);
}

GraphicsHandler::~GraphicsHandler() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void GraphicsHandler::draw_frame() const {
    SDL_SetRenderDrawColor(renderer, BG_COLOR.r, BG_COLOR.g, BG_COLOR.b, 0);
    SDL_RenderClear(renderer);

    for (ScreenEntity* entity : screen_entities) {
        entity->draw();
    }

    SDL_RenderPresent(renderer);
}