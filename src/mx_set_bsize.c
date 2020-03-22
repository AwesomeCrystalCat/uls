#include "uls.h"

char *mx_set_bsize(struct stat *buff, const char *str) {
    int num = buff->st_size;
    int tmp = num;

    if (str[0] == 'l')
        return mx_itoa(0);
    tmp = num % 1024;
    num = num / 1024;
    if (tmp != 0)
        num = num + 4;
    return mx_itoa(num);
}
