#pragma once

#include "screen_entity.h"
#include "../key_listener.h"
#include "../board.h"
#include <iostream>


class Grid : public ScreenEntity, public KeyListener {
public:
    Grid(SDL_Renderer* renderer, Board* board);

    void draw() override;
    void on_key_event(SDL_Event &event) override;

private:
    static const int CELL_WIDTH = 15;
    static const int CELL_HEIGHT = 15;

    static const int ZOOM_SENSITIVITY = 1;

    struct Coordinates {
        int x;
        int y;
    };

    Board* board;

    int x_offset = 0;
    int y_offset = 0;

    int zoom = 0;

    int width;
    int height;

    Coordinates grid_to_board(const int x, const int y) const;
};