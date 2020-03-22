#include "uls.h"

static void print_inode_l(t_elem **arr, t_all *ptr, int k) {
    mx_print_spaces(ptr->inode_n - mx_strlen(arr[k]->inode));
    write(1, arr[k]->inode, mx_strlen(arr[k]->inode));
    write(1, " ", 1);
}

static void print_bsize_l(t_elem **arr, t_all *ptr, int k) {
    mx_print_spaces(ptr->bsize_n - mx_strlen(arr[k]->bsize));
    write(1, arr[k]->bsize, mx_strlen(arr[k]->bsize));
    write(1, " ", 1);
}

static void print_out_l(t_elem **arr, t_all *ptr, int k, e_flg *flag) {
    write(1, arr[k]->mode, mx_strlen(arr[k]->mode));
    write(1, &arr[k]->acl, 1);
    mx_print_spaces(mx_l_link(arr, ptr) - mx_strlen(arr[k]->link) + 1);
    write(1, arr[k]->link, mx_strlen(arr[k]->link));
    write(1, " ", 1);
    if (!flag[g]) {
        write(1, arr[k]->uid, mx_strlen(arr[k]->uid));
        mx_print_spaces(mx_l_uid(arr, ptr) - mx_strlen(arr[k]->uid) + 2);
    }
    (flag[g] && flag[o]) ? write(1, "  ", 2) : 0;
    if (!flag[o]) {
        write(1, arr[k]->gid, mx_strlen(arr[k]->gid));
        mx_print_spaces(mx_l_gid(arr, ptr) - mx_strlen(arr[k]->gid) + 2);
    }
    mx_print_spaces(mx_l_size(arr, ptr) - mx_strlen(arr[k]->size));
    write(1, arr[k]->size, mx_strlen(arr[k]->size));
    write(1, " ", 1);
    write(1, arr[k]->r_time, mx_strlen(arr[k]->r_time));
    write(1, " ", 1);
}

void mx_output_l(t_elem **arr, t_all *ptr, e_flg *flag) {
    for (int k = 0; k < ptr->count; k++) {
        flag[i] ? print_inode_l(arr, ptr, k) : 0;
        flag[s] ? print_bsize_l(arr, ptr, k) : 0;
        print_out_l(arr, ptr, k, flag);
        if (flag[g_big] && isatty(1) == 1)
            mx_print_colored(arr[k], arr[k]->path);
        else
            write(1, arr[k]->name, mx_strlen(arr[k]->name));
        if (arr[k]->mode[0] == 'l')
            mx_print_link(arr, ptr, k);
        if (flag[p] && arr[k]->mode[0] == 'd')
            write(1, "/", 1);
        mx_p_xattr(arr, ptr, k, flag);
        if (k + 1 != ptr->count)
            write(1, "\n", 1);
    }
}
