#include "uls.h"

void mx_cols_and_rows(t_elem **dir_args, t_all *ptr, e_flg *flag) {
    int total_len = 0;

    ptr->line_len = mx_get_win_size();
    for (int k = 0; k < ptr->count; k++) {
        total_len += mx_strlen(dir_args[k]->name) + MX_TAB;
        if (flag[i])
            total_len += mx_get_inode_num(ptr, dir_args) + 1;
        if (flag[s])
            total_len += mx_get_bsize_num(ptr, dir_args) + 1;
    }
    if (total_len > ptr->line_len) {
        mx_find_name_len(dir_args, ptr, flag);
        //mx_get_real_cols(ptr, dir_args, flag);
    }
    else
        ptr->lines = 1;
    // printf("line_len = %d\n", ptr->line_len);
    // printf("name_len = %d\n", ptr->name_len);
    // printf("count = %d\n", ptr->count);
    // printf("cols = %d\n", ptr->cols);
    // printf("lines = %d\n", ptr->lines);
}
