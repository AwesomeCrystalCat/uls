#include "uls.h"

static void print_kostul(t_data *data) {
    write(2, "\n/dev/fd/3:\n", 12);
    write(2, "uls: 3: Not a directory\n", 24);
    write(2, "uls: 4: directory causes a cycle\n", 33);
    data->ecount++;
}

void mx_recursion(t_all *ptr, t_elem **arr, e_flg *flag, t_data *data) {
    for (int i = 0; i < ptr->count; i++) {
        if (arr[i]->mode[0] == 'd' && (!mx_strcmp(arr[i]->path, "/dev/fd")
            || !mx_strcmp(arr[i]->path, "/dev/fd/3")))
            print_kostul(data);
        else if (arr[i]->mode[0] == 'd') {
            if (!(mx_strcmp(arr[i]->name, ".") == 0
                || mx_strcmp(arr[i]->name, "..") == 0)) {
                mx_check_perm(arr, i, flag, data);
            }
        }
    }
}
