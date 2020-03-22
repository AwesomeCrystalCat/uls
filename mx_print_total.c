#include "uls.h"

const char *mx_print_total(t_elem **arr, t_all *ptr) {
    unsigned int total = 0;

    for (int k = 0; k < ptr->count; k++) {
        total += arr[k]->b;
    }
    return mx_itoa((int)total); 
}
