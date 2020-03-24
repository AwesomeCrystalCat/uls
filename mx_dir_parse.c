#include "uls.h"

void mx_dir_parse(e_flg *flag, const char *dir) {
    t_all *ptr = malloc(sizeof(t_all));

    ptr->count = mx_files_count(dir, flag);
    if (flag[r_big])
        mx_print_fname(flag, dir);
    mx_write_total(NULL, ptr, flag);
    if (ptr->count) {
        t_elem **arr = (t_elem **)malloc(sizeof(t_elem *) * ptr->count);
        mx_read_dir(arr, dir, flag);
        mx_write_total(arr, ptr, flag);
        mx_sorting(arr, ptr->count, flag);
        mx_cols_and_rows(arr, ptr, flag);
        mx_printer(arr, ptr, flag);
        if (flag[r_big])
            mx_recursion(ptr, arr, flag);
        mx_big_destroyer(arr, ptr->count);
    }
    free(ptr);
}
