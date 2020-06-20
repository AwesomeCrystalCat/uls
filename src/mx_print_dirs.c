#include "uls.h"

static void check_slash(t_data *data, t_elem **arr, e_flg *flag, int j) {
    if (arr[j]->name[0] == '/' && data->dcount > 1 && flag[r_big]) {
        data->cur_dir = 0;
        mx_dir_parse(flag, arr[j]->name, data);
    }
    else if (data->dcount > 1) {
        data->cur_dir = -1;
        mx_dir_parse(flag, arr[j]->name, data);
    }
    else {
        data->cur_dir = -2;
        mx_dir_parse(flag, arr[j]->name, data);
    }
    if (j < data->dcount - 1)
        write(1, "\n", 1);
}

void mx_print_dirs(t_data *data, e_flg *flag) {
    t_elem **arr = (t_elem **)malloc(sizeof(t_elem *) * data->dcount);

    for (int i = 0; i < data->dcount; i++)
        arr[i] = mx_getstats(data->directs[i], ".", flag);
    mx_sorting(arr, data->dcount, flag);
    for (int j = 0; j < data->dcount; j++) {
        check_slash(data, arr, flag, j);
    }
    mx_big_destroyer(arr, data->dcount);
}
