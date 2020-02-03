#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    char *new = 0;

    if (!s1)
        return 0;
    new = mx_strncpy(mx_strnew(n), s1, n);
    return new;
}
