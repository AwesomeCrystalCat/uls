#include "uls.h"

void print_space(int num) {
    for (int i = 0; i < num; i++) {
        write(1, " ", 1);
    }
}

void mx_output_x(t_elem **dir_args, t_all *ptr, e_flg *flag) {
    int limit = ptr->cols;
    int cur = 0;

    for (int j = 0; j < ptr->count;) {
        for (; j < limit; j++) {
            cur = ptr->name_len;
            if (flag[i]) {
                print_space(ptr->inode_n - mx_strlen(dir_args[j]->inode));
                write(1, dir_args[j]->inode, mx_strlen(dir_args[j]->inode));
                write(1, " ", 1);
                cur -= ptr->inode_n + 1;
            }
            if (flag[s]) {
                print_space(ptr->bsize_n - mx_strlen(dir_args[j]->bsize));
                write(1, dir_args[j]->bsize, mx_strlen(dir_args[j]->bsize));
                write(1, " ", 1);
                cur -= ptr->bsize_n + 1;
            }
            if (isatty(1) == 1) {
                if (flag[g_big])
                    mx_print_colored(dir_args[j]->name, dir_args[j]->path);
                else {
                    write(1, dir_args[j]->name, mx_strlen(dir_args[j]->name));
                }
            }
            else {
                write(1, dir_args[j]->name, mx_strlen(dir_args[j]->name));
                write(1, "\n", 1);
            }
            cur -= mx_strlen(dir_args[j]->name);
            print_space(cur);
            if ((j + 1) % ptr->cols == 0)
                write(1, "\n", 1);
        }
        if (limit + ptr->cols < ptr->count)
            limit += ptr->cols;
        else 
            limit = ptr->count;
    }
}