#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    if (arr == NULL || *arr == NULL) 
        return -1;
    if (left >= right)
        return 0;
    int count = 0;
    int middle = left + (right - left) / 2;
    char *pivot = arr[middle];
    int i = left;
    int j = right;
    while (i <= j) {
        while (comparator(arr[i], pivot) < 0) {
            i++;
        }
        while (comparator(arr[j], pivot) > 0) {
            j--;
        }
        if (i <= j) {
            swap(&arr[i], &arr[j], &count);
            i++;
            j--;
        }
    }
    if (left < j)
        count += mx_quicksort(arr, left, j);

    if (right > i)
        count += mx_quicksort(arr, i, right);
    return count;
}

int comparator(char *s1, char *s2) {
    return mx_strlen(s1) - mx_strlen(s2);
}

void swap(char **s1, char **s2, int *count) {
    if (comparator(*s1, *s2) == 0) return;
    char *t = *s1;
    *s1 = *s2;
    *s2 = t;
    (*count)++;                        
}


