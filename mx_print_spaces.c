#include "uls.h"

void mx_print_spaces(int num) {
    for (int i = 0; i < num; i++) {
        write(1, " ", 1);
    }
}
