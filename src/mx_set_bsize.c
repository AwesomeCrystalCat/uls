#include "uls.h"

char *mx_set_bsize(struct stat *buff, const char *str) {
    int num = buff->st_size;
    int tmp = num;
    int bytes = 0;

    if (str[0] == 'l')
        return mx_itoa(0);
    while (num > 1024) {
        bytes++;
        tmp = num % 1024;
        num = num / 1024;
    }
    if (tmp != 0)
        bytes++;
    bytes = bytes * 4;
    return mx_itoa(bytes);
}
