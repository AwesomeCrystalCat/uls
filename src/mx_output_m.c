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

static void print_inode_bs_m(t_elem **arr, t_all *ptr, int k, e_flg *flag) {
    if (flag[i]) {
        mx_print_spaces(ptr->inode_n - mx_strlen(arr[k]->inode));
        write(1, arr[k]->inode, mx_strlen(arr[k]->inode));
        write(1, " ", 1);
        ptr->limit += ptr->inode_n + 1;
    }
    if (flag[s]) {
        mx_print_spaces(ptr->bsize_n - mx_strlen(arr[k]->bsize));
        write(1, arr[k]->bsize, mx_strlen(arr[k]->bsize));
        write(1, " ", 1);
        ptr->limit += ptr->bsize_n + 1;
    }
}

static void output_m_file(t_elem **arr, t_all *ptr, e_flg *flag) {
    for (int k = 0; k < ptr->count; k++) {
        if (find_all(ptr, arr, k, flag) + ptr->limit + 2 > 81) {
            write(1, "\n", 1);
            ptr->limit = 0;
        }
        print_inode_bs_m(arr, ptr, k, flag);
        if (flag[g_big] && isatty(1) == 1)
            mx_print_colored(arr[k], arr[k]->path); 
        else
            mx_printstr(arr[k]->name);
        if (flag[p] && arr[k]->mode[0] == 'd')
            write(1, "/", 1);
        if (k + 1 != ptr->count)
            write(1, ", ", 2);
        if (k + 2 != ptr->count)
            ptr->limit += mx_strlen(arr[k]->name) + 2;
        else
            ptr->limit += mx_strlen(arr[k]->name);
    }
}

static void space_check(t_elem **arr, t_all *ptr, int k) {
    if (k + 1 != ptr->count)
        write(1, ", ", 2);
    if (k + 2 != ptr->count)
        ptr->limit += mx_strlen(arr[k]->name) + 2;
    if (k + 1 == ptr->count && k + 2 == ptr->count)
        ptr->limit += mx_strlen(arr[k]->name); 
}

void mx_output_m(t_elem **arr, t_all *ptr, e_flg *flag) {
    if (isatty(1) == 1) {
        for (int k = 0; k < ptr->count; k++) {
            if (find_all(ptr, arr, k, flag)
                + ptr->limit + 2 > ptr->line_len) {
                write(1, "\n", 1);
                ptr->limit = 0;
            }
            print_inode_bs_m(arr, ptr, k, flag);
            if (flag[g_big])
                mx_print_colored(arr[k], arr[k]->path);
            else
                mx_printstr(arr[k]->name);
            if (flag[p] && arr[k]->mode[0] == 'd')
                write(1, "/", 1);
            space_check(arr, ptr, k);
        }
    }
    else
        output_m_file(arr, ptr, flag);
}
