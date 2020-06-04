#include "uls.h"

void mx_write_total(t_elem **arr, t_all *ptr, e_flg *flag) {
    if (flag[s] || flag[l] || flag[o] || flag[g]) {
        if (arr) {
            const char *tmp = mx_print_total(arr, ptr);

            write(1, "total ", 6);
            mx_printstr(tmp);
            write(1, "\n", 1);
            free((void *)tmp);
        }
    }
}
