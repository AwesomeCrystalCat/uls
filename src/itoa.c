#include "uls.h"

int mx_positive_atoi(char *str) {
    int res = 0;
    int j = 1;

    int len = mx_strlen(str) - 1;
    for (int i = len; i >= 0; i--) {
        res += (str[i] - 48) * j;
        j *= 10;
    }
    return res;
}
