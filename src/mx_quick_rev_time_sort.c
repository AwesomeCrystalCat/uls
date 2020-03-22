#include "uls.h"

static void swap_elems(t_elem *arr1, t_elem *arr2) {
    t_elem temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}

static int wild_cmp(char *s1, char *s2) {
    int i = 0;

    for (; s1[i] == s2[i] && (s1[i] >= '0' && s1[i] <= '9')
         && (s2[i] >= '0' && s2[i] <= '9'); i++);
    if ((s1[i] >= '0' && s1[i] <= '9') || (s2[i] >= '0' && s2[i] <= '9'))
        return s1[i] - s2[i];
    else {
        while (s1[i] == s2[i]) {
            if (s1[i] == '\0' && s2[i] == '\0')
                return 0;
            i++;
        }
        return s2[i] - s1[i];
    }
}

void mx_quick_rev_time_sort(t_elem **ptr, int left, int right) {
    int i = 0;
    int j = 0;
    int pivot = 0;

    if (left < right) {
        pivot = left;
        i = left;
        j = right;
        while (i < j) {
            while (wild_cmp(ptr[i]->f_time, ptr[pivot]->f_time) < 0 && i < right)
                i++;
            while (wild_cmp(ptr[j]->f_time, ptr[pivot]->f_time) > 0)
                j--;
            if (i < j)
                swap_elems(ptr[i], ptr[j]);
        }
        mx_quick_rev_time_sort(ptr, left, j - 1);
        mx_quick_rev_time_sort(ptr, j + 1, right);
    }
}
