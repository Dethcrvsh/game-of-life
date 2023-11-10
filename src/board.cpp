#include "board.h"
#include <iostream>
#include <string>


Board::Board() {
    history.push_back(std::bitset<WIDTH * HEIGHT>());
    grid = &history.back();

    KeyListener::register_listener(this);

    toggle_cell(2, 3);
    toggle_cell(3, 3);
    toggle_cell(4, 3);
    toggle_cell(5, 7);
    toggle_cell(6, 7);
    toggle_cell(8, 3);
}

int Board::get_width() const { return WIDTH; }
int Board::get_height() const { return HEIGHT; }

bool Board::is_cell_alive(int x, int y) const {
    return (*grid)[y * WIDTH + x];
}

void Board::toggle_cell(int x, int y) {
    (*grid)[y * WIDTH + x] = !is_cell_alive(x, y);
}

void Board::evolve() {
    std::bitset<WIDTH * HEIGHT> new_grid;

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int x = i / WIDTH;
        int y = i % WIDTH;

        int alive_count = get_living_neighbours(x, y);

        if (alive_count < 2) {
            new_grid[y * WIDTH + x] = false;
        } else if (alive_count == 3) {
            new_grid[y * WIDTH + x] = true;
        } else if (alive_count > 3) {
            new_grid[y * WIDTH + x] = false;
        } else {
            new_grid[y * WIDTH + x] = (*grid)[y * WIDTH + x];
        }
    }

    history.push_back(new_grid);
    grid = &history.back();
}

void Board::print() const {
    std::string buf = "";

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        if (i % WIDTH == 0) {
            std::cout << buf << std::endl;
            buf = "";
        }
        buf += (*grid)[i] ? "1" : "0";
    }
}

int Board::get_living_neighbours(int x, int y) {
    // Do not count the cell itself
    int alive_count = -(int) (*grid)[y * WIDTH + x];

    for (int i = 0; i < 9; i++) {
        int neigh_x = x - 1 + i / 3;
        int neigh_y = y - 1 + i % 3;

        bool is_out_of_bounds = (
            neigh_x < 0 ||
            neigh_y < 0 ||
            neigh_x >= WIDTH ||
            neigh_y >= HEIGHT
        );

        if (!is_out_of_bounds) {
            alive_count += is_cell_alive(neigh_x, neigh_y);
        }
    }

    return alive_count;
}

void Board::on_key_event(SDL_Event &event) {
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
        evolve();
    }

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_DOWN) {
        if (history.size() > 0 ) {
            grid = &history[history.size() - 1];
            history.pop_back();
        }
    }
}
