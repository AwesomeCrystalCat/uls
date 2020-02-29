#include "uls.h"
#include <stdio.h>

void mx_print_files(t_data *data, e_flg *flag) {
    t_all *ptr = (t_all *)malloc(sizeof(t_all));
    t_elem **arr = (t_elem **)malloc(sizeof(t_elem *) * data->fcount);

    ptr->count = data->fcount;
    for (int i = 0; data->files[i] != NULL; i++)
        arr[i] = mx_getstats(data->files[i], ".", flag);
    if (flag[r]) {
        if (flag[s_big])
            mx_quick_rev_size_sort(arr, 0, data->fcount - 1);
        else if (flag[t])
            mx_quick_rev_time_sort(arr, 0, data->fcount - 1);
        else
            mx_quick_rev_elem_sort(arr, 0, data->fcount - 1);
    }
    else {
        if (flag[s_big])
            mx_quick_size_sort(arr, 0, data->fcount - 1);
        else if (flag[t])
            mx_quick_time_sort(arr, 0, data->fcount - 1);
        else
            mx_quick_elem_sort(arr, 0, data->fcount - 1);
    }
    if (isatty(1) == 1) {
        for (int i = 0; data->files[i] != NULL; i++) {
            if (flag[l])
                mx_output_l(arr, data->fcount, flag);
            else if (flag[g_big]) {
                mx_print_colored(arr[i]->name, arr[i]->path);
                mx_printstr("        ");
            }
            else {
                write(1, arr[i]->name, mx_strlen(arr[i]->name));
                mx_printstr("        ");
            }
        }
    }
}
