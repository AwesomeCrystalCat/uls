#include "uls.h"
#include <stdio.h>

void mx_output_l(t_elem **arr, int num, e_flg *flag) {
for (int k = 0; k < num; k++) {
        // printf("%s\n", arr[i]->path);
        if (flag[s]) {
            write(1, arr[k]->bsize, mx_strlen(arr[k]->bsize));
            write(1, " ", 1);
        }
        if (flag[i]) {
            write(1, arr[k]->inode, mx_strlen(arr[k]->inode));
            write(1, " ", 1);
        }
        write(1, arr[k]->mode, mx_strlen(arr[k]->mode));
        write(1, " ", 1);
        write(1, arr[k]->link, mx_strlen(arr[k]->link));
        write(1, " ", 1);
        write(1, arr[k]->uid, mx_strlen(arr[k]->uid));
        write(1, " ", 1);
        write(1, arr[k]->gid, mx_strlen(arr[k]->gid));
        write(1, " ", 1);
        write(1, arr[k]->size, mx_strlen(arr[k]->size));
        write(1, " ", 1);
        write(1, arr[k]->r_time, mx_strlen(arr[k]->r_time));
        write(1, " ", 1);
        if (isatty(1) == 1) {
            if (flag[g_big])
                mx_print_colored(arr[k]->name, arr[k]->path);
            else
                write(1, arr[k]->name, mx_strlen(arr[k]->name));
        }
        else
            write(1, arr[k]->name, mx_strlen(arr[k]->name));
        write(1, "\n", 1);
    }
}
