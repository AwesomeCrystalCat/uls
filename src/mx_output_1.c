#include "uls.h"

void mx_output_1(t_elem **arr, t_all *ptr, e_flg *flag, int cur) {
    for (int k = 0; k < ptr->count; k++) {
        cur = mx_print_is(arr, ptr, flag, k);
        if (flag[p] && arr[k]->mode[0] == 'd')
            write(1, "/", 1);
        if (k + 1 != ptr->count)
            write(1, "\n", 1);
    }
}
