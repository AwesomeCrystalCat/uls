#include "libmx.h"


int mx_bubble_sort(char **arr, int size) {
    char *buf = 0;
    int count = 0;
    if (arr == NULL || size <= 0)
        return 0;
    for (int i = 0; i < size -1; i++) {
        for (int j = 0; j < size -1 -i; j++) {
            if (mx_strcmp(arr[j], arr[j+1]) > 0) {
                    buf = arr[j];
                    arr[j] = arr [j+1];
                    arr[j+1] = buf;
                    count++;
            }
        }
    }
    return count;
}



