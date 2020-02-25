#include "uls.h"

void mx_find_name_len(t_elem **arr, t_all *ptr) {
    ptr->name_len = 0;
    for (int i = 0; i < ptr->count; i++) {
        if (mx_strlen(arr[i]->name) > ptr->name_len)
            ptr->name_len = mx_strlen(arr[i]->name);
    }
    ptr->line_len = mx_get_win_size();
    ptr->lines = ptr->line_len / ptr->name_len;
}
