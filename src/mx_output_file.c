#include "uls.h"

static void print_newrow(int j, int c) {
    if (j != c)
        write(1, "\n", 1);
}

void mx_output_file(t_elem **arr, t_all *ptr, e_flg *flag) {
    for (int j = 0; j < ptr->count; j++) {
        int cur = ptr->name_len;

        if (flag[i]) {
            mx_print_spaces(ptr->inode_n - mx_strlen(arr[j]->inode));
            write(1, arr[j]->inode, mx_strlen(arr[j]->inode));
            write(1, " ", 1);
            cur -= ptr->inode_n + 1;
        }
        if (flag[s]) {
            mx_print_spaces(ptr->bsize_n - mx_strlen(arr[j]->bsize));
            write(1, arr[j]->bsize, mx_strlen(arr[j]->bsize));
            write(1, " ", 1);
            cur -= ptr->bsize_n + 1;
        }
        write(1, arr[j]->name, mx_strlen(arr[j]->name));
        if (flag[p] && arr[j]->mode[0] == 'd')
            write(1, "/", 1);
        print_newrow(j + 1, ptr->count);
    }
}
