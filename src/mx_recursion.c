#include "uls.h"

void mx_recursion(t_all *ptr, t_elem **arr, e_flg *flag, t_data *data) {
    for (int i = 0; i < ptr->count; i++) {
        if (arr[i]->mode[0] == 'd') {
            if (!(mx_strcmp(arr[i]->name, ".") == 0
                || mx_strcmp(arr[i]->name, "..") == 0)) {
                mx_check_perm(arr, i, flag, data);
            }
        }
    }
}
