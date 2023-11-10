#pragma once

#include <SDL.h>
#include <vector>
#include "../board.h"
#include "screen_entity.h"


class GraphicsHandler {
public:
    GraphicsHandler(Board* board);
    ~GraphicsHandler();

    // Draw the next frame
    void draw_frame() const;
private:
    //Screen dimension constants
    static const int WINDOW_WIDTH = 640 * 2;
    static const int WINDOW_HEIGHT = 480 * 2;

    static constexpr const char* WINDOW_TITLE = "Game of Life";

    SDL_Color BG_COLOR = {241, 234, 255, 1};

    //The window we'll be rendering to
    SDL_Window* window;
    SDL_Renderer* renderer;

    Board* board;

    // Entities that should be drawn to the screen
    std::vector<ScreenEntity*> screen_entities;
};