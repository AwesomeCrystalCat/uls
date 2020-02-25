#include "uls.h"

int get_high(t_all *ptr, int cols) {
    int height = MX_TERM / cols;

    if (MX_TERM % cols > 0)
        height++;
    return height;
}

int find_longest_in_the_row(t_all *ptr, t_elem **dir_args, int cols, int cur) {
    int longest = 0;
    int height = get_high(ptr, cols);

    for (int i = 0; i < height && cur < ptr->count; i++) {
        if (mx_strlen(dir_args[cur]->name) > longest)
            longest = mx_strlen(dir_args[cur]->name);
        cur++;
    }
    return longest;
}

void mx_get_real_cols(t_all *ptr, t_elem **dir_args) {
    int limit = MX_TERM + MX_TAB;
    int cols = ptr->lines;
    int longest = 0;
    int cur = 0;
    int real_mf_cols = 0;

    while (limit > 0) {
        longest = find_longest_in_the_row(ptr, dir_args, cols, cur);
        limit = limit - (longest + MX_TAB);
        real_mf_cols++;
        if (cur + get_high(ptr, cols) < ptr->count)
            cur += get_high(ptr, cols);
        else if (limit > 0) {
            limit = MX_TERM;
            real_mf_cols = 0;
            cur = 0;
            cols++;
        }
    }
    if (limit == 0)
        ptr->lines = get_high(ptr, cols);
    else
        ptr->lines = get_high(ptr, cols - 1);
}
