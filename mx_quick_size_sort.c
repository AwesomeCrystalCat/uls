#include "uls.h"

static int partition(t_elem **arr, int left, int right) {
    int mid = left + (right - left) / 2;
    int pivot = arr[mid]->size_i;
    t_elem *temp;

    while (left <= right) {
        while (arr[left]->size_i > pivot)
            left++;
        while (arr[right]->size_i < pivot)
            right--;
        if (left <= right) {
            if (arr[left]->size_i != arr[right]->size_i) {
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

void mx_quick_size_sort(t_elem **arr, int left, int right) {
    int pivot = 0;

    if (arr) {
        if (left < right) {
            pivot = partition(arr, left, right);
            if (left < pivot - 1)
                mx_quick_size_sort(arr, left, pivot - 1);
            if (pivot < right)
                mx_quick_size_sort(arr, pivot, right);
        }
    }
}
