#include "uls.h"

void mx_quick_cmp_sort(char **arr, int left, int right) {
    if (arr != NULL) {
        int i, j, pivot;
        char *temp;

        if (left < right) {
            pivot = left;
            i = left;
            j = right;
            while (i < j) {
                while (strcmp(arr[i],arr[pivot]) < 0 && i < right)
                    i++;
                while (strcmp(arr[j],arr[pivot]) > 0)
                    j--;
                if (i < j) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        mx_quick_cmp_sort(arr, left, j - 1);
        mx_quick_cmp_sort(arr, j + 1, right);
        }
   }
}
