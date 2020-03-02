#include "uls.h"
#include <stdio.h>

void print_p(int num) {
    for (int i = 0; i < num; i++) {
        write(1, " ", 1);
    }
}

int largest_link(t_elem **arr, t_all *ptr) {
    int largest = 0;

    for (int k = 0; k < ptr->count; k++) {
        if (mx_strlen(arr[k]->link) > largest) 
            largest = mx_strlen(arr[k]->link);
    }
    return largest;
}

int largest_uid(t_elem **arr, t_all *ptr) {
    int largest = 0;

    for (int k = 0; k < ptr->count; k++) {
        if (mx_strlen(arr[k]->uid) > largest) 
            largest = mx_strlen(arr[k]->uid);
    }
    return largest;
}

int largest_gid(t_elem **arr, t_all *ptr) {
    int largest = 0;

    for (int k = 0; k < ptr->count; k++) {
        if (mx_strlen(arr[k]->gid) > largest) 
            largest = mx_strlen(arr[k]->gid);
    }
    return largest;
}

int largest_size(t_elem **arr, t_all *ptr) {
    int largest = 0;

    for (int k = 0; k < ptr->count; k++) {
        if (mx_strlen(arr[k]->size) > largest) 
            largest = mx_strlen(arr[k]->size);
    }
    return largest;
}

void mx_output_l(t_elem **arr, t_all *ptr, e_flg *flag) {
    for (int k = 0; k < ptr->count; k++) {
        if (flag[i]) {
            print_p(ptr->inode_n - mx_strlen(arr[k]->inode));
            write(1, arr[k]->inode, mx_strlen(arr[k]->inode));
            write(1, " ", 1);
        }
        if (flag[s]) {
            print_p(ptr->bsize_n - mx_strlen(arr[k]->bsize));
            write(1, arr[k]->bsize, mx_strlen(arr[k]->bsize));
            write(1, " ", 1);
        }
        write(1, arr[k]->mode, mx_strlen(arr[k]->mode));
        print_p(largest_link(arr, ptr) - mx_strlen(arr[k]->link) + 1);
        write(1, arr[k]->link, mx_strlen(arr[k]->link));
        print_p(largest_uid(arr, ptr) - mx_strlen(arr[k]->uid) + 1);
        write(1, arr[k]->uid, mx_strlen(arr[k]->uid));
        print_p(largest_gid(arr, ptr) - mx_strlen(arr[k]->gid) + 1);
        write(1, arr[k]->gid, mx_strlen(arr[k]->gid));
        print_p(largest_size(arr, ptr) - mx_strlen(arr[k]->size) + 1);
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
        if (k + 1 != ptr->count)
            write(1, "\n", 1);
    }
}
