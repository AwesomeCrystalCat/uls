#include "uls.h"

void mx_print_dirs(t_data *data, e_flg *flag) {
    struct stat buff;
    t_elem **arr = (t_elem **)malloc(sizeof(t_elem *) * data->dcount);

    for (int i = 0; i < data->dcount; i++) {
        arr[i] = mx_getstats(data->directs[i], ".", flag);
        if (arr[i]->mode[1] != '-'
            && arr[i]->mode[4] != '-' && arr[i]->mode[7] != '-') {
            mx_dir_parse(flag, data->directs[i]);
            if (i < data->dcount - 1)
                write(1, "\n", 1);
        }
        else
            mx_denied_error(arr, i, flag);
        free(arr[i]);
    }
}
