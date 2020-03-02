#include "uls.h"

int mx_get_inode_num(t_all *ptr, t_elem **arr) {
    int res = 0;

    for (int i = 0; i < ptr->count; i++) {
        if (mx_strlen(arr[i]->inode) > res)
            res = mx_strlen(arr[i]->inode);
    }
    ptr->inode_n = res;
    return res;
}
