#include "libmx.h"
int mx_binary_search(char **arr, int size, const char *s, int *count) {
    *count = 0;
    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right) {
        (*count)++;
         mid = (left + right) / 2;
         if (mx_strcmp(arr[mid], s) < 0)
             left = mid + 1;
         else if (mx_strcmp(arr[mid], s) > 0)
            right = mid - 1;
         else
            return mid;
    }
     *count = 0;
    return -1;
}


