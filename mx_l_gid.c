#include "uls.h"

int mx_l_gid(t_elem **arr, t_all *ptr) {
    int largest = 0;

    for (int k = 0; k < ptr->count; k++) {
        if (mx_strlen(arr[k]->gid) > largest)
            largest = mx_strlen(arr[k]->gid);
    }
    return largest;
}
