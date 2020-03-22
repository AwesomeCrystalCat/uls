#include "uls.h"

int mx_get_win_size(void) {
    struct winsize w;
    int cols = 0;

    ioctl(1, TIOCGWINSZ, &w);
    cols = w.ws_col;
    return cols;
}
