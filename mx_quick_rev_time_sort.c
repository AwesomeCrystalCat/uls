#include "uls.h"

static int partition(t_elem **arr, int left, int right) {
    int mid = left + (right - left) / 2;
    int pivot = arr[mid]->u_time;
    t_elem *temp;

    while (left <= right) {
        while (arr[left]->u_time < pivot)
            left++;
        while (arr[right]->u_time > pivot)
            right--;
        if (left <= right) {
            if (arr[left]->u_time != arr[right]->u_time) {
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

void mx_quick_rev_time_sort(t_elem **arr, int left, int right) {
    int pivot = 0;

    if (arr) {
        if (left < right) {
            pivot = partition(arr, left, right);
            if (left < pivot - 1)
                mx_quick_rev_time_sort(arr, left, pivot - 1);
            if (pivot < right)
                mx_quick_rev_time_sort(arr, pivot, right);
        }
    }
}
