#include "uls.h"

const char *mx_print_total(t_elem **arr, t_all *ptr) {
    unsigned int total = 0;
    const char *res;

    for (int k = 0; k < ptr->count; k++) {
        total += arr[k]->b;
    }
    res = mx_itoa(total);
    return res;
}
