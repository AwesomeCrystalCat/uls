#include "uls.h"

int mx_l_uid(t_elem **arr, t_all *ptr) {
    int largest = 0;

    for (int k = 0; k < ptr->count; k++) {
        if (mx_strlen(arr[k]->uid) > largest)
            largest = mx_strlen(arr[k]->uid);
    }
    return largest;
}
