#pragma once

#include <bitset>
#include <vector>

#include "key_listener.h"


class Board : public KeyListener {
public:
    Board();

    int get_width() const;
    int get_height() const;

    bool is_cell_alive(int x, int y) const;
    void toggle_cell(int x, int y);
    void evolve();
    void print() const;
    void on_key_event(SDL_Event &event) override;

private:
    static const int WIDTH = 64;
    static const int HEIGHT = 64;

    std::bitset<WIDTH * HEIGHT>* grid; 
    std::vector<std::bitset<WIDTH * HEIGHT>> history;

    int get_living_neighbours(int x, int y);
};
