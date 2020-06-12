#include "uls.h"

static int mx_numlen(int num) {
    int len = 0;

    if (num < 0)
        len = 1;
    while (num > 0 || -num > 0 || num == -2147483648) {
        num /= 10;
        len++;
    }
    if (len == 0)
        len = 1;
    return len;
}

char *mx_itoa(int number) {
    int len = mx_numlen(number);
    char *result = mx_strnew(len);
    int min = 0;

    if (number < 0) {
        result[0] = '-';
        min++;
        number *= -1;
    }
    for (int i = len - 1; i >= min; i--) {
        result[i] = (number % 10) + '0';
        number /= 10;
    }
    return result;
}
