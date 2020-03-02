#include "uls.h"

void print_s(int num) {
    for (int i = 0; i < num; i++) {
        write(1, " ", 1);
    }
}

void mx_output_1(t_elem **arr, t_all *ptr, e_flg *flag) {
    for (int k = 0; k < ptr->count; k++) {
        if (flag[s]) {
            print_s(ptr->bsize_n - mx_strlen(arr[k]->bsize));
            mx_printstr(arr[k]->bsize);
            write(1, " ", 1);
        }
        if (flag[i]) {
            print_s(ptr->inode_n - mx_strlen(arr[k]->inode));
            mx_printstr(arr[k]->inode);
            write(1, " ", 1);
        }
        if (isatty(1) == 1) {
            if (flag[g_big])
                mx_print_colored(arr[k]->name, arr[k]->path);
            else {
                mx_printstr(arr[k]->name);
            }
        }
        else if (isatty(1) != 1)
            mx_printstr(arr[k]->name);
        if (k + 1 != ptr->count)
            write(1, "\n", 1);
    }
}
