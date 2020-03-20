#include "uls.h"

void write_total(t_elem **arr, t_all *ptr, e_flg *flag) {
    if (flag[s] || flag[l] || flag[o] || flag[g]) {
        if (arr) {
            write(1, "total ", 6); 
            mx_printstr(mx_print_total(arr, ptr));
            write(1, "\n", 1);
        }
        if (ptr->count == 0)
            write(1, "total 0\n", 9);
    }
}

void mx_dir_parse(e_flg *flag, const char *dir) {
    t_all *ptr = malloc(sizeof(t_all));

    ptr->count = mx_files_count(dir, flag);
    if (flag[r_big])
        mx_print_fname(flag, dir);
    write_total(NULL, ptr, flag);
    if (ptr->count) {
        t_elem **arr = (t_elem **)malloc(sizeof(t_elem *) * ptr->count);
        mx_read_dir(arr, dir, flag);
        write_total(arr, ptr, flag);
        mx_sorting(arr, ptr->count, flag);
        mx_cols_and_rows(arr, ptr, flag);
        mx_printer(arr, ptr, flag);
        if (flag[r_big])
            mx_recursion(ptr, arr, flag);
    }
}
