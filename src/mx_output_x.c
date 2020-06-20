#include "uls.h"

void mx_output_x(t_elem **dir_args, t_all *ptr, e_flg *flag, int cur) {
    int limit = ptr->cols;

    if (isatty(1) == 1) {
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
    else
        mx_output_file_x(dir_args, ptr, flag, cur);
}
