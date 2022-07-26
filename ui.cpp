//
// Created by pasri on 23/07/2022.
//

#include "ui.h"
#include <iostream>

ui::ui(WINDOW* w, int x, int y) : MAXX(x), MAXY(y), uiWindow(w), m_Matrix(x, y) {

    //resize_window(uiWindow,MAXX, MAXY);

    if (!uiWindow) {
        std::cout << "Cannot initialize window. Terminating." << std::endl;
        exit(EXIT_FAILURE);
    }

    start_color();
    if (!has_colors() || !can_change_color()) {
        std::cout << "Warning. Your terminal can't handle colors. Terminating." << std::endl;
        exit(EXIT_FAILURE);
    }

    set_colors();

}

void ui::set_colors() {
    for (short i = 0; i < 8; ++i) {
        init_pair(static_cast<short>(i+1), i, COLOR_BLACK);
    }
    for (short i = 0; i <=5; i++){
        init_color(i,0,static_cast<short>(i*200),0);
    }
    init_color(6,1000,1000,1000);
    // or init_pair(6,COLOR_WHITE,COLOR_BLACK) to use white
}

ui::~ui() {
    delwin(uiWindow);
    endwin();
    refresh();
}

void ui::show() {
    int cellIntensity;
    for (int i=0; i<MAXX; ++i){
        for (int j = 0; j<MAXY ; ++j) {
            cellIntensity = m_Matrix.at(i,j).intensity;
            // set color map specified with pair in set_color() according to cell intensity.
            color_set(color_map[cellIntensity], NULL);
            mvaddch(j, i, m_Matrix.at(i,j).symbol);
        }
    }
    refresh();
}

void ui::update() {
    m_Matrix.update();
}
