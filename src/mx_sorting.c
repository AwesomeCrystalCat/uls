#include "uls.h"

void mx_sorting(t_elem **arr, t_all *ptr, e_flg *flag) {
    if (flag[r]) {
        if (flag[s_big])
            mx_quick_rev_size_sort(arr, 0, ptr->count - 1);
        else if (flag[t])
            mx_quick_rev_time_sort(arr, 0, ptr->count - 1);
        else
            mx_quick_rev_elem_sort(arr, 0, ptr->count - 1);
    }
    else {
        if (flag[s_big])
            mx_quick_size_sort(arr, 0, ptr->count - 1);
        else if (flag[t])
            mx_quick_time_sort(arr, 0, ptr->count - 1);
        else
            mx_quick_elem_sort(arr, 0, ptr->count - 1);
    }
}
