#include "uls.h"

int mx_get_bsize_num(t_all *ptr, t_elem **arr) {
    int res = 0;

    for (int i = 0; i < ptr->count; i++) {
        if (mx_strlen(arr[i]->bsize) > res)
            res = mx_strlen(arr[i]->bsize);
    }
    ptr->bsize_n = res;
    return res;
}
