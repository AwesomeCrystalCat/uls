#include "uls.h"
#include <stdio.h>

void mx_print_files(t_data *data) {
    t_elem **arr = (t_elem **)malloc(sizeof(t_elem *) * data->fcount);

    for (int i = 0; data->files[i] != NULL; i++)
        arr[i] = mx_getstats(data->files[i]);
    mx_quick_elem_sort(arr, 0, data->fcount - 1);
    for (int i = 0; data->files[i] != NULL; i++)
        mx_output_l(arr, data->fcount);
}
