#include "uls.h"

static void print_name(e_flg *flag, const char *name, int i, t_elem **arr) {
    if (mx_strcmp(name, ".") != 0) {
        write(1, "\n", 1);
        write(1, ".", 1);
        if (name[0] == '/')
            write(1, name, mx_strlen(name));
        else {
            write(1, "/", 1);
            write(1, name, mx_strlen(name));
        }
        write(1, ":", 1);
        mx_denied_error(arr, i, flag);
    }
}

void mx_recursion(t_all *ptr, t_elem **arr, e_flg *flag) {
    for (int i = 0; i < ptr->count; i++) {
        if (arr[i]->mode[0] == 'd') {
            if (!(mx_strcmp(arr[i]->name, ".") == 0
                || mx_strcmp(arr[i]->name, "..") == 0)) {
                if (arr[i]->mode[1] != '-'
                    && arr[i]->mode[4] != '-'
                    && arr[i]->mode[7] != '-') {
                    write(1, "\n", 1);
                    mx_dir_parse(flag, arr[i]->path);
                }
                else
                    print_name(flag, arr[i]->name, i, arr);
            }
        }
    }
}
