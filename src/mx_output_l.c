#include "uls.h"
#include <stdio.h>

int larg_link(t_elem **arr, t_all *ptr) {
    int largest = 0;

    for (int k = 0; k < ptr->count; k++) {
        if (mx_strlen(arr[k]->link) > largest) 
            largest = mx_strlen(arr[k]->link);
    }
    return largest;
}

int larg_uid(t_elem **arr, t_all *ptr) {
    int largest = 0;

    for (int k = 0; k < ptr->count; k++) {
        if (mx_strlen(arr[k]->uid) > largest) 
            largest = mx_strlen(arr[k]->uid);
    }
    return largest;
}

int larg_gid(t_elem **arr, t_all *ptr) {
    int largest = 0;

    for (int k = 0; k < ptr->count; k++) {
        if (mx_strlen(arr[k]->gid) > largest) 
            largest = mx_strlen(arr[k]->gid);
    }
    return largest;
}

int larg_size(t_elem **arr, t_all *ptr) {
    int largest = 0;

    for (int k = 0; k < ptr->count; k++) {
        if (mx_strlen(arr[k]->size) > largest) 
            largest = mx_strlen(arr[k]->size);
    }
    return largest;
}

static void kostul_l_i(t_elem **arr, t_all *ptr, int k) {
    mx_print_spaces(ptr->inode_n - mx_strlen(arr[k]->inode));
    write(1, arr[k]->inode, mx_strlen(arr[k]->inode));
    write(1, " ", 1);
}

static void kostul_l_s(t_elem **arr, t_all *ptr, int k) {
    mx_print_spaces(ptr->bsize_n - mx_strlen(arr[k]->bsize));
    write(1, arr[k]->bsize, mx_strlen(arr[k]->bsize));
    write(1, " ", 1);
}

static void kostul_l(t_elem **arr, t_all *ptr, int k, e_flg *flag) {
    write(1, arr[k]->mode, mx_strlen(arr[k]->mode));
    flag[dog] ? write(1, &arr[k]->acl, 1) : 0;
    mx_print_spaces(larg_link(arr, ptr) - mx_strlen(arr[k]->link) + 2);
    write(1, arr[k]->link, mx_strlen(arr[k]->link));
    write(1, " ", 1);
    if (!flag[g]) {
        write(1, arr[k]->uid, mx_strlen(arr[k]->uid));
        mx_print_spaces(larg_uid(arr, ptr) - mx_strlen(arr[k]->uid) + 2);
    }
    if (!flag[o]) {
        write(1, arr[k]->gid, mx_strlen(arr[k]->gid));
        mx_print_spaces(larg_gid(arr, ptr) - mx_strlen(arr[k]->gid) + 1);
    }
    mx_print_spaces(larg_size(arr, ptr) - mx_strlen(arr[k]->size) + 1);
    write(1, arr[k]->size, mx_strlen(arr[k]->size));
    write(1, " ", 1);
    write(1, arr[k]->r_time, mx_strlen(arr[k]->r_time));
    write(1, " ", 1);
}

void mx_output_l(t_elem **arr, t_all *ptr, e_flg *flag) {
    for (int k = 0; k < ptr->count; k++) {
        flag[i] == 1 ? kostul_l_i(arr, ptr, k) : 0;
        flag[s] == 1 ? kostul_l_s(arr, ptr, k) : 0;
        kostul_l(arr, ptr, k, flag);
        if (flag[g_big] && isatty(1) == 1)
            mx_print_colored(arr[k]->name, arr[k]->path);
        else
            write(1, arr[k]->name, mx_strlen(arr[k]->name));
        if (k + 1 != ptr->count)
            write(1, "\n", 1);
    }
}
