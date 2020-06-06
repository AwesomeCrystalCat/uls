#include "uls.h"

char *mx_set_bsize(struct stat *buff, const char *str) {
    int num = buff->st_size;
    int tmp = num;
    char *res = NULL;

    if (str[0] == 'l') {
        res = mx_itoa(0);
        return res;
    }
    tmp = num % 1024;
    num = num / 1024;
    if (tmp != 0)
        num = num + 4;
    res = mx_itoa(num);
    return res;
}
