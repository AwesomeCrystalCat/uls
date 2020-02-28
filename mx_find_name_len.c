#include "uls.h"
#include <stdio.h>

static int find_all_len(t_all *ptr, t_elem **dir_args, int cur, e_flg *flag) {
    int res = 0;

    res += mx_strlen(dir_args[cur]->name) + MX_TAB;
    if (flag[i])
        res += ptr->inode_n + 1;
    if (flag[s])
        res += ptr->bsize_n + 1;
    return res;
}

void mx_find_name_len(t_elem **arr, t_all *ptr, e_flg *flag) {
    int res = 0;
    for (int j = 0; j < ptr->count; j++) {
        if (find_all_len(ptr, arr, j, flag) > res) {
            res = mx_strlen(arr[j]->name) + MX_TAB;
            if (flag[i])
                res += ptr->inode_n + 1;
            if (flag[s])
                res += ptr->bsize_n + 1;
        }
    }
    ptr->line_len = mx_get_win_size();
    ptr->name_len = res;
    ptr->lines = ptr->line_len / ptr->name_len;
}
