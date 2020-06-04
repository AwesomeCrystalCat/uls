#include "uls.h"

void mx_big_destroyer(t_elem **arr, int n) {
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
        if (arr[k]->path_link != NULL)
            free((void *)arr[k]->path_link);
        free(arr[k]);
    }
    free(arr);
}
