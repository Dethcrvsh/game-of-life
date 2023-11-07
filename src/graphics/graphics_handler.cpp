#include "graphics_handler.h"
#include "grid.h"
#include "screen_entity.h"

GraphicsHandler::GraphicsHandler() {
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

    screen_entities.push_back(new Grid(renderer));
}

GraphicsHandler::~GraphicsHandler() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void GraphicsHandler::draw_frame() {
    SDL_SetRenderDrawColor(renderer, 0, BG_COLOR.r, BG_COLOR.g, BG_COLOR.b);
    SDL_RenderClear(renderer);

    for (ScreenEntity* entity : screen_entities) {
        entity->draw();
    }

    SDL_RenderPresent(renderer);
}