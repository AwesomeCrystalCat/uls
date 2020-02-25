#include "uls.h"

void mx_output_1(t_elem **arr, int num, e_flg *flag) {
    for (int k = 0; k < num; k++) {
        if (flag[s]) {
            mx_printstr(arr[k]->bsize);
            write(1, " ", 1);
        }
        if (flag[i]) {
            mx_printstr(arr[k]->inode);
            write(1, " ", 1);
        }
        if (isatty(1) == 1) {
            if (flag[g_big])
                mx_print_colored(arr[k]->name);
            else {
                mx_printstr(arr[k]->name);
                write(1, "\n", 1);
            }
        }
        else if (isatty(1) != 1)
            mx_printstr(arr[k]->name);
    }
}