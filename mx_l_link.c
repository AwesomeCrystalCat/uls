#include "uls.h"

int mx_l_link(t_elem **arr, t_all *ptr) {
    int largest = 0;

    for (int k = 0; k < ptr->count; k++) {
        if (mx_strlen(arr[k]->link) > largest)
            largest = mx_strlen(arr[k]->link);
    }
    return largest;
}
