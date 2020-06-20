#include "uls.h"

static void cols_and_rows_x(t_elem **dir_args, t_all *ptr, e_flg *flag) {
    ptr->line_len = 70;
    mx_find_name_len(dir_args, ptr, flag);
    if (ptr->count * ptr->name_len < ptr->line_len) {
        ptr->lines = 1;
        ptr->cols = ptr->count;
    }
    else {
        ptr->cols = ptr->line_len / ptr->name_len;
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

void mx_output_file_x(t_elem **dir_args, t_all *ptr, e_flg *flag, int cur) {
    int limit;

    cols_and_rows_x(dir_args, ptr, flag);
    limit = ptr->cols;
    for (int j = 0; j < ptr->count;) {
        for (; j < limit; j++) {
            cur = mx_print_is(dir_args, ptr, flag, j);
            if ((j + 1) % ptr->cols == 0 && j + 1 != ptr->count)
                write(1, "\n", 1);
            else if (j + 1 != ptr->count)
                mx_print_spaces(cur);
        }
        if (limit + ptr->cols < ptr->count)
            limit += ptr->cols;
        else
            limit = ptr->count;
    }
}
