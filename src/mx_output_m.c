#include "uls.h"

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

static int print_inode_m(t_elem **arr, t_all *ptr, int k, int limit) {
    mx_print_spaces(ptr->inode_n - mx_strlen(arr[k]->inode));
    write(1, arr[k]->inode, mx_strlen(arr[k]->inode));
    write(1, " ", 1);
    limit += ptr->inode_n + 1;
    return limit;
}

static int print_bsize_m(t_elem **arr, t_all *ptr, int k, int limit) {
    mx_print_spaces(ptr->bsize_n - mx_strlen(arr[k]->bsize));
    write(1, arr[k]->bsize, mx_strlen(arr[k]->bsize));
    write(1, " ", 1);
    limit += ptr->bsize_n + 1;
    return limit;
}

static void output_m_file(t_elem **arr, t_all *ptr, e_flg *flag, int limit) {
    for (int k = 0; k < ptr->count; k++) {
        if (find_all(ptr, arr, k, flag) + limit + 2 > 81) {
            write(1, "\n", 1);
            limit = 0;
        }
        flag[i] == 1 ? limit = print_inode_m(arr, ptr, k, limit) : limit;
        flag[s] == 1 ? limit = print_bsize_m(arr, ptr, k, limit) : limit;
        if (flag[g_big] && isatty(1) == 1)
            mx_print_colored(arr[k], arr[k]->path); 
        else
            mx_printstr(arr[k]->name);
        if (flag[p] && arr[k]->mode[0] == 'd')
            write(1, "/", 1);
        if (k + 1 != ptr->count)
            write(1, ", ", 2);
        if (k + 2 != ptr->count)
            limit += mx_strlen(arr[k]->name) + 2;
        else
            limit += mx_strlen(arr[k]->name);
    }
}

void mx_output_m(t_elem **arr, t_all *ptr, e_flg *flag, int limit) {
    if (isatty(1) == 1) {
        for (int k = 0; k < ptr->count; k++) {
            if (find_all(ptr, arr, k, flag) + limit + 2 > ptr->line_len) {
                write(1, "\n", 1);
                limit = 0;
            }
            flag[i] ? limit = print_inode_m(arr, ptr, k, limit) : limit;
            flag[s] ? limit = print_bsize_m(arr, ptr, k, limit) : limit;
            flag[g_big] ? (mx_print_colored(arr[k], arr[k]->path)) : 0;
            (!flag[g_big]) ? (mx_printstr(arr[k]->name)) : 0;
            if (flag[p] && arr[k]->mode[0] == 'd')
                write(1, "/", 1);
            k + 1 != ptr->count ? write(1, ", ", 2) : 0;
            k + 2 != ptr->count ? limit += mx_strlen(arr[k]->name) + 2 : 0;
            if (k + 1 == ptr->count && k + 2 == ptr->count)
                limit += mx_strlen(arr[k]->name); 
        }
    }
    else
        output_m_file(arr, ptr, flag, limit);
}
