#pragma once

#include <bitset>
#include <vector>


class Board {
public:
    Board();

    int get_width() const;
    int get_height() const;

    bool is_cell_alive(int x, int y) const;
    void toggle_cell(int x, int y);
    void evolve();
    void print() const;

private:
    static const int WIDTH = 10;
    static const int HEIGHT = 10;

    std::bitset<WIDTH * HEIGHT>* grid; 
    std::vector<std::bitset<WIDTH * HEIGHT>> history;

    int get_living_neighbours(int x, int y);
};
