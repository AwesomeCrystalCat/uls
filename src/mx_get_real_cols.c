#include "uls.h"

static int find_all_len(t_all *ptr, t_elem **dir_args, int cur) {
    int res = 0;

    res += mx_strlen(dir_args[cur]->name) + MX_TAB;
    if (ptr->flag[i])
        res += ptr->inode_n + 1;
    if (ptr->flag[s])
        res += ptr->bsize_n + 1;
    return res;
}

int find_longest_in_the_row(t_all *ptr, t_elem **dir_args, int height, int cur) {
    int longest = 0;

    for (int j = 0; j < height && cur < ptr->count; j++) {
        if (find_all_len(ptr, dir_args, cur) > longest)
            longest = find_all_len(ptr, dir_args, cur);
        cur++;   
    }
    return longest;
}

void mx_get_real_cols(t_all *ptr, t_elem **dir_args, e_flg *flag) {
    int limit = MX_TERM + MX_TAB;
    int height = ptr->count / ptr->lines;
    int longest = 0;
    int cur = 0;

    if (ptr->count % ptr->lines > 0)
        height++;
    ptr->flag = flag;
    while (limit > 0) {
        longest = find_longest_in_the_row(ptr, dir_args, height, cur);
        limit = limit - longest;
        if (cur + height < ptr->count)
            cur += height;
        else if (limit > 0) {
            limit = MX_TERM + MX_TAB;
            cur = 0;
            height--;
        }
    }
    ptr->lines = height + 1;
}
