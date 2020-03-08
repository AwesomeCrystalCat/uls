#include "uls.h"

int mx_print_is(t_elem **dir_args, t_all *ptr, e_flg *flag, int j) {
    int cur = ptr->name_len;

    if (flag[i]) {
        mx_print_spaces(ptr->inode_n - mx_strlen(dir_args[j]->inode));
        write(1, dir_args[j]->inode, mx_strlen(dir_args[j]->inode));
        write(1, " ", 1);
        cur -= ptr->inode_n + 1;
    }
    if (flag[s]) {
        mx_print_spaces(ptr->bsize_n - mx_strlen(dir_args[j]->bsize));
        write(1, dir_args[j]->bsize, mx_strlen(dir_args[j]->bsize));
        write(1, " ", 1);
        cur -= ptr->bsize_n + 1;
    }
    if (flag[g_big] && isatty(1) == 1)
        mx_print_colored(dir_args[j]->name, dir_args[j]->path);
    else
        write(1, dir_args[j]->name, mx_strlen(dir_args[j]->name));
    cur -= mx_strlen(dir_args[j]->name);
    return cur;
}
