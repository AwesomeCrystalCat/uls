#include "uls.h"

void mx_get_inode_num(t_all *ptr, t_elem **arr, e_flg *flag) {
    int res = 0;

    if (flag[i]) {
        for (int i = 0; i < ptr->count; i++) {
            if (mx_strlen(arr[i]->inode) > res)
                res = mx_strlen(arr[i]->inode);
        }
        ptr->inode_n = res;
    }
}
