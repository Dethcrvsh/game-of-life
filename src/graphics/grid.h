#pragma once

#include "screen_entity.h"
#include "../key_listener.h"
#include "../board.h"
#include <iostream>
#include <string>


class Grid : public ScreenEntity, public KeyListener {
public:
    Grid(SDL_Renderer* renderer, Board* board, int screen_width, const int screen_height);

    void draw() override;
    void on_key_event(SDL_Event &event) override;

private:
    static const int CELL_WIDTH = 15;
    static const int CELL_HEIGHT = 15;
    static const int CELL_PADDING = 2;

    static const int ZOOM_SENSITIVITY = 1;

    SDL_Color OUTLINE_COLOR = {208, 162, 247, 1};
    SDL_Color CELL_COLOR = {91, 8, 136, 1};

    struct Coordinates {
        int x;
        int y;
    };

    Board* board;

    int x_offset = 0;
    int y_offset = 0;

    int zoom = 1;

    int width;
    int height;

    int screen_width;
    int screen_height;

    // Remember zoom offset to correct the mouse position
    SDL_Point zoom_center = {0, 0};

    Coordinates grid_to_board(const int x, const int y) const;
};