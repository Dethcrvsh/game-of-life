#pragma once

#include <SDL.h>
#include <vector>
#include "screen_entity.h"


class GraphicsHandler {
public:
    GraphicsHandler();
    ~GraphicsHandler();

    // Draw the next frame
    void draw_frame();
private:
    //Screen dimension constants
    static const int WINDOW_WIDTH = 640;
    static const int WINDOW_HEIGHT = 480;
    
    static constexpr const char* WINDOW_TITLE = "Game of Life";

    struct BackgroundColor {
        int r = 0;
        int g = 0;
        int b = 0;
    } BG_COLOR;

    //The window we'll be rendering to
    SDL_Window* window;
    SDL_Renderer* renderer;

    // Entities that should be drawn to the screen
    std::vector<ScreenEntity*> screen_entities;
};