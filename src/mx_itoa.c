#include "uls.h"

static int mx_numlen(long long unsigned num) {
    int len = 0;

    while (num > 0) {
        num /= 10;
        len++;
    }
    if (len == 0)
        len = 1;
    return len;
}

char *mx_itoa(long long unsigned number) {
    int len = mx_numlen(number);
    char *result = mx_strnew(len);
    int min = 0;

    for (int i = len - 1; i >= min; i--) {
        result[i] = (number % 10) + '0';
        number /= 10;
    }
    return result;
}
