#include "uls.h"
#include <sys/ioctl.h>
#include <stdio.h>

int mx_get_win_size() {
    struct winsize w;
    int cols = 0;

    ioctl(1, TIOCGWINSZ, &w);
    cols = w.ws_col;
    // printf("win_size = %d/n", cols);
    return cols;
}
