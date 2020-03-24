#include "uls.h"

void mx_print_files(t_data *data, e_flg *flag) {
    t_all *ptr = (t_all *)malloc(sizeof(t_all));
    t_elem **arr = (t_elem **)malloc(sizeof(t_elem *) * data->fcount);

    ptr->count = data->fcount;
    for (int i = 0; i < ptr->count; i++)
        arr[i] = mx_getstats(data->files[i], ".", flag);
    mx_sorting(arr, ptr->count, flag);
    mx_cols_and_rows(arr, ptr, flag);
    mx_printer(arr, ptr, flag);
    mx_big_destroyer(arr, ptr->count);
    free(ptr);
}
