#include "uls.h"

void mx_cols_and_rows(t_elem **dir_args, t_all *ptr, e_flg *flag) {
    mx_get_inode_num(ptr, dir_args, flag);
    mx_get_bsize_num(ptr, dir_args, flag);
    ptr->line_len = mx_get_win_size();
    mx_find_name_len(dir_args, ptr, flag);
    if (ptr->count * ptr->name_len < ptr->line_len) {
        ptr->lines = 1;
        ptr->cols = ptr->count;
    }
    else {
        ptr->cols = ptr->line_len / ptr->name_len;
        ptr->cols == 0 ? ptr->cols++ : 0;
        ptr->lines = ptr->count / ptr->cols;
        if (ptr->count % ptr->cols > 0)
            ptr->lines++;
        if (ptr->cols > ptr->count / ptr->lines) {
            ptr->cols = ptr->count / ptr->lines;
            if (ptr->count % ptr->lines > 0)
                ptr->cols += 1;
        }
    }
}
