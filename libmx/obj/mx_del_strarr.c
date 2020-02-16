#include "libmx.h"

void mx_del_strarr(char ***arr) {
    char **p = *arr;
    while(*p) {
        mx_strdel(p);
        p++;
    }
    free(*arr);
    *arr = NULL;
}



