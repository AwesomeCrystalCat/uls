#include "uls.h"

void write_total(t_elem **dir_args, t_all *ptr) {
    write(1, "total ", 6); 
    mx_printstr(mx_print_total(dir_args, ptr));
    write(1, "\n", 1);
}

void mx_dir_parse(e_flg *flag, const char *dir) {
    t_all *ptr = malloc(sizeof(t_all));

    ptr->count = mx_files_count(dir, flag);
    mx_print_fname(flag, dir);
    if (ptr->count == 0)
        write(1, "total 0\n", 9);
    if (ptr->count) {
        t_elem **dir_args = (t_elem **)malloc(sizeof(t_elem *) * ptr->count);
        mx_read_dir(dir_args, dir, flag);
        if ((!flag[m] && !flag[c]) || flag[s] || flag[l]) {
            write_total(dir_args, ptr);
        }
        mx_sorting(dir_args, ptr, flag);
        mx_cols_and_rows(dir_args, ptr, flag);
        mx_printer(dir_args, ptr, flag);
        if (flag[r_big])
            mx_recursion(ptr, dir_args, flag);
    }
}
