#include "uls.h"
#include <stdio.h>

// add condition for flag_m

// int find_longest_in_the_row_1(t_all *ptr, t_elem **dir_args, int cols, int cur) {
//     int longest = 0;
//     int height = get_high(ptr, cols);

//     for (int i = 0; i < height && cur < ptr->count; i++) {
//         if (mx_strlen(dir_args[cur]->name) > longest)
//             longest = mx_strlen(dir_args[cur]->name);
//         cur++;
//     }
//     return longest;
// }

void mx_cols_and_rows(t_elem **dir_args, t_all *ptr, e_flg *flag) {
    int total_len = 0;

    for (int k = 0; k < ptr->count; k++) {
        total_len += mx_strlen(dir_args[k]->name) + MX_TAB;
        if (flag[i]) {
            total_len += mx_strlen(dir_args[k]->inode);
        }
        if (flag[s])
            total_len += mx_strlen(dir_args[k]->bsize);
    }
    if (total_len > MX_TERM) {
        mx_find_name_len(dir_args, ptr);
        mx_get_real_cols(ptr, dir_args);
    }
    else
        ptr->lines = 1;
    ptr->cols = ptr->count / ptr->lines;
    if (ptr->count % ptr->lines > 0)
        ptr->cols++;
}

void mx_dir_parse(e_flg *flag, const char *dir) {
    t_all *ptr = malloc(sizeof(t_all));
    ptr->count = mx_files_count(dir, flag);
    int spaces = 0;
    
    if (ptr->count) {
    t_elem **dir_args = (t_elem **)malloc(sizeof(t_elem *) * ptr->count);

    mx_read_dir(dir_args, dir, flag);
    mx_quick_elem_sort(dir_args, 0, ptr->count - 1);
    mx_cols_and_rows(dir_args, ptr, flag);
    if (flag[r_big])
        printf("%s:\n", dir);
    if (flag[l])
        mx_output_l(dir_args, ptr->count, flag);
    else if (flag[one])
        mx_output_1(dir_args, ptr->count, flag);
    else {
    printf("%d\n", ptr->count);
    printf("%d\n", ptr->lines);
    printf("%d\n", ptr->cols);
    // while (limit > 0) {
    //     longest = find_longest_in_the_row(ptr, dir_args, cols, cur);
    //     limit = limit - (longest + MX_TAB);
    //     real_mf_cols++;
    //     if (cur + get_high(ptr, cols) < ptr->count)
    //         cur += get_high(ptr, cols);
    //     else if (limit > 0) {
    //         limit = MX_TERM;
    //         real_mf_cols = 0;
    //         cur = 0;
    //         cols++;
    //     }
    // }
    for (int i = 0; i < ptr->lines - 1; i++) {
        // spaces = find_longest_in_the_row_1(ptr, dir_args, cols, cur);

        for (int j = 0; j < ptr->count; j++) {
            if (j % (ptr->count / (ptr->cols - 1)) == i) {
                printf("%s\n", dir_args[j]->name);
                printf("       ");
            }
        }
    }
    }
    if (flag[r_big]) {
        for (int i = 0; i < ptr->count; i++) {
            if (dir_args[i]->mode[0] == 'd') {
                if (!(mx_strcmp(dir_args[i]->name, ".") == 0 || mx_strcmp(dir_args[i]->name, "..") == 0))
                    mx_dir_parse(flag, dir_args[i]->name);
            }
        }
    }
    }
}
