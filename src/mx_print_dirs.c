#include "uls.h"

void mx_print_dirs(t_data *data, e_flg *flag) {
    struct stat buff;
    t_elem **arr = (t_elem **)malloc(sizeof(t_elem *) * data->dcount);

    for (int i = 0; i < data->dcount; i++)
        arr[i] = mx_getstats(data->directs[i], ".", flag);
    mx_sorting(arr, data->dcount, flag);
    for (int j = 0; j < data->dcount; j++) {
        if (arr[j]->mode[1] != '-'
            && arr[j]->mode[4] != '-' && arr[j]->mode[7] != '-') {
            if ((data->dcount > 1 || data->fcount) && !flag[r_big])
                mx_print_fname(flag, arr[j]->name);
            mx_dir_parse(flag, arr[j]->name);
            if (j < data->dcount - 1)
                write(1, "\n", 1);
        }
        else
            mx_denied_error(arr, i, flag);
        free(arr[j]);
    }
}
