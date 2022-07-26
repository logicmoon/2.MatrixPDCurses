#pragma once
#include "curses.h"
#include "TextMatrix.h"

const short color_map[MAX_INTENSITY+1] {1,2,2,3,
                                        3,3,4,4,
                                        4,4,4,5,
                                        3,6};


class ui {
public:
    ui(WINDOW* w, int x, int y);
    ~ui();
    void show();
    void update();
    static void set_colors();

private:
    int MAXX;
    int MAXY;
    WINDOW *uiWindow;
    TextMatrix m_Matrix;
};
