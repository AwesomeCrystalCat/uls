#include "uls.h"

static void over_thinking(t_data *data, e_flg *flag, t_elem **arr) {
    for (int j = 0; j < data->dcount; j++) {
        if (arr[j]->mode[1] != '-' && arr[j]->mode[4] != '-'
            && arr[j]->mode[7] != '-') {
            if (arr[j]->name[0] == '/' && (data->dcount > 1 || flag[r_big]))
                mx_dir_parse(flag, arr[j]->name, 0);
            else if (data->dcount > 1)
                mx_dir_parse(flag, arr[j]->name, -1);
            else
                mx_dir_parse(flag, arr[j]->name, -2);
            j < data->dcount - 1 ? write(1, "\n", 1) : 0;
        }
        else
            mx_denied_error(arr, i, flag);
    }
}

void mx_print_dirs(t_data *data, e_flg *flag) {
    struct stat buff;
    t_elem **arr = (t_elem **)malloc(sizeof(t_elem *) * data->dcount);

    for (int i = 0; i < data->dcount; i++)
        arr[i] = mx_getstats(data->directs[i], ".", flag);
    mx_sorting(arr, data->dcount, flag);
    over_thinking(data, flag, arr);
    mx_big_destroyer(arr, data->dcount);
}
