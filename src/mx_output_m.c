#include "uls.h"

void mx_output_m(t_elem **arr, int num, e_flg *flag) {
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
            if (flag[g_big]) {
                 if (k != 0)
                    write(1, ", ", 2);
                mx_print_colored(arr[k]->name, arr[k]->path);
            }
            else {
                if (k != 0)
                    write(1, ", ", 2);
                mx_printstr(arr[k]->name);
            }
        }
        else if (isatty(1) != 1) {
            if (k != 0)
                    write(1, ", ", 2);
            mx_printstr(arr[k]->name);
        }
    }
    write(1, "\n", 1);
}
