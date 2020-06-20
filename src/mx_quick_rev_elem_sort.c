#include "uls.h"

static void swap_elems(t_elem *arr1, t_elem *arr2) {
    t_elem temp = *arr1;

    *arr1 = *arr2;
    *arr2 = temp;
}

void mx_quick_rev_elem_sort(t_elem **ptr, int left, int right) {
    int i = 0;
    int j = 0;
    int pivot = 0;

    if (left < right) {
        pivot = left;
        i = left;
        j = right;
        while (i < j) {
            while (mx_strcmp(ptr[i]->name, ptr[pivot]->name) > 0
                   && i < right)
                i++;
            while (mx_strcmp(ptr[j]->name, ptr[pivot]->name) < 0)
                j--;
            if (i < j)
                swap_elems(ptr[i], ptr[j]);
        }
        mx_quick_rev_elem_sort(ptr, left, j - 1);
        mx_quick_rev_elem_sort(ptr, j + 1, right);
    }
}
