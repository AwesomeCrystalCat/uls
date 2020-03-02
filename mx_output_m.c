#include "uls.h"

void print_sp(int num) {
    for (int i = 0; i < num; i++) {
        write(1, " ", 1);
    }
}

static int find_all(t_all *ptr, t_elem **dir_args, int cur, e_flg *flag) {
    int res = 0;

    res += mx_strlen(dir_args[cur]->name) + 2;
    if (flag[i] && flag[s])
        res += ptr->inode_n + ptr->bsize_n;
    else if (flag[i])
        res += ptr->inode_n - 6;
    else if (flag[s])
        res += ptr->bsize_n - 2;
    return res;
}

void mx_output_m(t_elem **arr, t_all *ptr, e_flg *flag) {
    int limit = 0;

    for (int k = 0; k < ptr->count; k++) {
        if (find_all(ptr, arr, k, flag) + limit + 2 > ptr->line_len) {
            write(1, "\n", 1);
            limit = 0;
        }
        else {
            if (flag[i]) {
                print_sp(ptr->inode_n - mx_strlen(arr[k]->inode));
                write(1, arr[k]->inode, mx_strlen(arr[k]->inode));
                write(1, " ", 1);
                limit += ptr->inode_n + 1;
            }
            if (flag[s]) {
                print_sp(ptr->bsize_n - mx_strlen(arr[k]->bsize));
                write(1, arr[k]->bsize, mx_strlen(arr[k]->bsize));
                write(1, " ", 1);
                limit += ptr->bsize_n + 1;
            }
            if (isatty(1) == 1) {
                if (flag[g_big]) {
                    mx_print_colored(arr[k]->name, arr[k]->path); 
                    if (k + 1 != ptr->count)
                        write(1, ", ", 2);
                }
                else {
                    mx_printstr(arr[k]->name); 
                    if (k + 1 != ptr->count)
                        write(1, ", ", 2);
                }
            }
            else {
                mx_printstr(arr[k]->name);
                if (k + 1 != ptr->count)
                    write(1, ", ", 2);
            }
        }
        limit += mx_strlen(arr[k]->name) + 2;  
    }
}
