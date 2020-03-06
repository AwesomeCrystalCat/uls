#include "uls.h"
#include <stdio.h>

static int find_all_len(t_all *ptr, t_elem **dir_args, int cur, e_flg *flag) {
    int res = 0;

    res += mx_strlen(dir_args[cur]->name) + MX_TAB;
    if (flag[i] && flag[s])
        res += ptr->inode_n + ptr->bsize_n - 5;
    else if (flag[i])
        res += ptr->inode_n - 6;
    else if (flag[s])
        res += ptr->bsize_n - 5;
    return res;
}

void mx_find_name_len(t_elem **arr, t_all *ptr, e_flg *flag) {
    int res = 0;
    for (int j = 0; j < ptr->count; j++) {
        if (find_all_len(ptr, arr, j, flag) > res) {
            res = find_all_len(ptr, arr, j, flag);
        }
    }
    // printf("inode_n = %d\n", ptr->inode_n);
    // printf("bsize_n = %d\n", ptr->bsize_n);
    // printf("res = %d\n", res);
    ptr->name_len = res;
}
