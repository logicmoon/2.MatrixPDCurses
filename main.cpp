#include "ui.h"
#include <Windows.h>
#include <iostream>
#include "curses.h"

const int ITER {500};
const int REFRESH_DELAY {20};
const int mROWS {379};
const int mCOLS {68};

int main(int argc, char** argv) {

    WINDOW* terminalWindow = initscr();
    if(!terminalWindow) {
        std::cout << "Could not initialize terminal window. Terminating." << std::endl;
        return EXIT_FAILURE;
    }

    ui matrixUI(terminalWindow, mROWS, mCOLS);

    nodelay(terminalWindow, true);
    while (wgetch(stdscr) == ERR) {
        matrixUI.update();
        matrixUI.show();
        Sleep(REFRESH_DELAY);
    }

    return 0;
}
