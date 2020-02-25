#include "uls.h"
#include <stdio.h>

void mx_output_l(t_elem **arr, int num, e_flg *flag) {
for (int k = 0; k < num; k++) {
        // printf("%s\n", arr[i]->path);
        if (flag[s])
            printf("%s ", arr[k]->bsize);
        if (flag[i])
            printf("%s ", arr[k]->inode);
        printf("%s ", arr[k]->mode);
        printf("%s ", arr[k]->link);
        printf("%s ", arr[k]->uid);
        printf("%s ", arr[k]->gid);
        printf("%s ", arr[k]->size);
        printf("%s ", arr[k]->ctime);
        if (isatty(1) == 1) {
            if (flag[g_big])
                mx_print_colored(arr[k]->name);
            else
                printf("%s\n", arr[k]->name);
        }
        else
            printf("%s\n", arr[k]->name);
    }
}
