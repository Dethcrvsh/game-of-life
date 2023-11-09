#pragma once

#include "screen_entity.h"
#include "../key_listener.h"
#include <iostream>


class Grid : public ScreenEntity, public KeyListener {
public:
    Grid(SDL_Renderer* renderer, int width, int height) : ScreenEntity(renderer), width(width), height(height) {};

    void draw() override;
    void on_key_event(SDL_Event &event) override;

private:
    static const int CELL_WIDTH = 25;
    static const int CELL_HEIGHT = 25;

    int x_offset = 0;
    int y_offset = 0;

    int zoom = 1;

    int width;
    int height;
};