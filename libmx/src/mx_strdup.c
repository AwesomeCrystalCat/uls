#include "../inc/libmx.h"

char *mx_strdup(const char *s1) {
    char *new = 0;

    if (!s1)
        return 0;
    new = mx_strcpy(mx_strnew(mx_strlen(s1)), s1);
    return new;
}
