#include "uls.h"
#include <stdio.h>

void mx_output_l(t_elem **arr, int num) {
for (int i = 0; i < num; i++) {
        // printf("%s\n", arr[i]->path);
        printf("%s ", arr[i]->bsize);
        printf("%s ", arr[i]->inode);
        printf("%s ", arr[i]->mode);
        printf("%s ", arr[i]->link);
        printf("%s ", arr[i]->uid);
        printf("%s ", arr[i]->gid);
        printf("%s ", arr[i]->size);
        printf("%s ", arr[i]->ctime);
        printf("%s\n", arr[i]->name);
        // mx_print_colored(arr[i]->name);
    }
}
