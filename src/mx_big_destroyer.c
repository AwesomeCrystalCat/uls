#include "uls.h"

void mx_big_destroyer(t_elem **arr, t_all *ptr) {
    for (int k = 0; k < ptr->count; k++) {
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
