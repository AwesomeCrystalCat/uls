#include "uls.h"

static void swap_elems(t_elem *arr1, t_elem *arr2) {
    t_elem temp = *arr1;

    *arr1 = *arr2;
    *arr2 = temp;
}

static int wild_cmp_r(t_elem **ptr, int j, int pivot) {
    if (mx_strcmp(ptr[j]->size, ptr[pivot]->size) == 0)
        return mx_strcmp(ptr[pivot]->name, ptr[j]->name);
    else {
        if (mx_strlen(ptr[j]->size) == mx_strlen(ptr[pivot]->size))
            return mx_strcmp(ptr[j]->size, ptr[pivot]->size);
        else if (mx_strlen(ptr[j]->size) > mx_strlen(ptr[pivot]->size))
            return 1;
        else
            return -1;
    }
    return 0;
}

void mx_quick_size_sort(t_elem **ptr, int left, int right) {
    int i = 0;
    int j = 0;
    int pivot = 0;

    if (left < right) {
        pivot = left;
        i = left;
        j = right;
        while (i < j) {
            while (wild_cmp_r(ptr, i, pivot) > 0
                   && i < right)
                i++;
            while (wild_cmp_r(ptr, j, pivot) < 0)
                j--;
            if (i < j)
                swap_elems(ptr[i], ptr[j]);
        }
        mx_quick_size_sort(ptr, left, j - 1);
        mx_quick_size_sort(ptr, j + 1, right);
    }
}
