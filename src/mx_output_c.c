#include "uls.h"

static int count_len_c(t_all *ptr, int j, int cur) {
    if (j + ptr->lines < ptr->count) {
        j += ptr->lines;
        mx_print_spaces(cur);
    }
    else if (j / ptr->lines == ptr->cols - 2) {
        j = (j - (ptr->lines * (ptr->cols - 2))) + 1;
        write(1, "\n", 1);
    }
    else if (j / ptr->lines == ptr->cols - 1) {
        j = (j - (ptr->lines * (ptr->cols - 1))) + 1;
        write(1, "\n", 1);
    }
    return j;
}

void mx_output_c(t_elem **arr, t_all *ptr, e_flg *flag, int cur) {
    if (isatty(1) == 1) {
        for (int j = 0; j <= ptr->count;) {
            cur = mx_print_is(arr, ptr, flag, j);
            if ((j + ptr->lines == ptr->lines * ptr->cols - 1
                && ptr->lines * ptr->cols != ptr->count)
                || (j + 1 == ptr->count
                && ptr->lines * ptr->cols == ptr->count))
                break;
            j = count_len_c(ptr, j, cur);
        }
    }
    else
        mx_output_file(arr, ptr, flag);
}
