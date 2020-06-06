#include "uls.h"

void mx_dir_parse(e_flg *flag, const char *dir, int cur_dir) {
    t_all *ptr = malloc(sizeof(t_all));

    ptr->count = mx_files_count(dir, flag);
    mx_print_fname(flag, dir, cur_dir);
    mx_write_total(NULL, ptr, flag);
    if (ptr->count) {

        t_elem **arr = (t_elem **)malloc(sizeof(t_elem *) * ptr->count);
        mx_read_dir(arr, dir, flag);
        mx_write_total(arr, ptr, flag);
        mx_sorting(arr, ptr->count, flag);

        //printf("HERE\n");
        mx_cols_and_rows(arr, ptr, flag);

        mx_printer(arr, ptr, flag);
        if (flag[r_big])
            mx_recursion(ptr, arr, flag, cur_dir);
        mx_big_destroyer(arr, ptr->count);
    }
    free(ptr);
}
