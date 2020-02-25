#include "uls.h"

void mx_quick_elem_sort(t_elem **ptr, int left, int right) {
    if (ptr != NULL) {
        int i, j, pivot;
        t_elem *temp;

        if (left < right) {
            pivot = left;
            i = left;
            j = right;
            while (i < j) {
                while (strcmp(ptr[i]->s_name, ptr[pivot]->s_name) < 0 && i < right)
                    i++;
                while (strcmp(ptr[j]->s_name, ptr[pivot]->s_name) > 0)
                    j--;
                if (i < j) {
                    temp = ptr[i];
                    ptr[i] = ptr[j];
                    ptr[j] = temp;
                }
            }
        mx_quick_elem_sort(ptr, left, j - 1);
        mx_quick_elem_sort(ptr, j + 1, right);
        }
   }
}
