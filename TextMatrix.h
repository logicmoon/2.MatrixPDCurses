#pragma once
#include <iostream>
#include <boost/multi_array.hpp>
#include <random>

const short N_DRIPS {500};
const short MAX_INTENSITY {13};
const short MIN_INTENSITY {2};

struct cell {
    char symbol {0};
    short intensity {0};
};

struct drip {
    std::pair<int,int> dPos {0,0};
    bool live {false};
    bool bright {false};
};

class TextMatrix {
public:
    TextMatrix(short x, short y) : getxPos(0, x-1),
    cols(y), rows(x), tMatrix(boost::extents[x][y]) {};

    ~TextMatrix() = default;

    TextMatrix (const TextMatrix& otherMatrix) = delete;
    TextMatrix (TextMatrix&& otherMatrix) = delete;

    TextMatrix& operator=(const TextMatrix& otherMatrix) = delete;
    TextMatrix& operator=(TextMatrix&& otherMatrix) = delete;

    void fade_change();
    void add_drips();
    void update_drips();

    void update();

    cell& at(int x, int y);

    std::uniform_int_distribution<int> getxPos;

private:
    int cols;
    int rows;
    boost::multi_array<cell,2> tMatrix;
    drip m_drips[N_DRIPS];
};
