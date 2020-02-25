#include "uls.h"
#include <stdio.h>

static int partition(t_elem **arr, int left, int right) {
    int mid = left + (right - left) / 2;
    int pivot = mx_strlen(arr[mid]->name);
    t_elem *temp;

    while (left <= right) {
        while (mx_strlen(arr[left]->name) > pivot)
            left++;
        while (mx_strlen(arr[right]->name) < pivot)
            right--;
        if (left <= right) {
            if (mx_strlen(arr[left]->name) != mx_strlen(arr[right]->name)) {
                temp = arr[right];
                arr[right] = arr[left];
                arr[left] = temp;
            }
            left++;
            right--;
        }
    }
    return left;
}

void mx_quicksort(t_elem **arr, int left, int right) {
    int pivot = 0;

    if (arr) {
        if (left < right) {
            pivot = partition(arr, left, right);
            if (left < pivot - 1)
                mx_quicksort(arr, left, pivot - 1);
            if (pivot < right)
                mx_quicksort(arr, pivot, right);
        }
    }
}
