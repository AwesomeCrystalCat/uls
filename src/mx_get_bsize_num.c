#include "uls.h"

void mx_get_bsize_num(t_all *ptr, t_elem **arr, e_flg *flag) {
    int res = 0;

    if (flag[s]) {
        for (int i = 0; i < ptr->count; i++) {
            if (mx_strlen(arr[i]->bsize) > res)
                res = mx_strlen(arr[i]->bsize);
        }
        ptr->bsize_n = res;
    }
}
