#include "uls.h"

static void big_destroyer(t_elem **arr, int n) {
    for (int k = 0; k < n; k++) {
        free((void *)arr[k]->name);
        free((void *)arr[k]->path);
        free(arr[k]->inode);
        free(arr[k]->mode);
        free(arr[k]->link);
        free(arr[k]->uid);
        free(arr[k]->gid);
        free(arr[k]->size);
        free(arr[k]->bsize);
        free(arr[k]->r_time);
        free(arr[k]->f_time);
        free(arr[k]);
    }
    free(arr);
}

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
    }
    big_destroyer(arr, data->dcount);
}
