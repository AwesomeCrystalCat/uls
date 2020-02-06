#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
if(!s1)
    return NULL;
char *t = mx_strnew(n);
    if(t) {
        mx_strncpy(t, s1, n);
    }

    return t;
}



