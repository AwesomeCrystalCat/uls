#include "uls.h"

void mx_cols_and_rows(t_elem **dir_args, t_all *ptr, e_flg *flag) {
    int total_len = 0;

    for (int k = 0; k < ptr->count; k++) {
        total_len += mx_strlen(dir_args[k]->name) + MX_TAB;
        if (flag[i])
            total_len += mx_get_inode_num(ptr, dir_args) + 1;
        if (flag[s])
            total_len += mx_get_bsize_num(ptr, dir_args) + 1;
    }
    if (total_len > MX_TERM) {
        mx_find_name_len(dir_args, ptr, flag);
        mx_get_real_cols(ptr, dir_args, flag);
    }
    else
        ptr->lines = 1;
    ptr->cols = ptr->count / ptr->lines;
    if (ptr->count % ptr->lines > 0)
        ptr->cols++;
}
