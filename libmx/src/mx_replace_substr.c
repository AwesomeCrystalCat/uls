#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {

    if (str == NULL || sub == NULL || replace == NULL) return NULL;
    if (mx_strlen(str) == 0 || mx_strlen(sub) == 0 || mx_strlen(replace) == 0)
        return (char *)str;

    char *old_str = (char *) str;
    char *new_str = NULL;
    repls(&new_str, old_str, (char *)sub, (char *)replace);
    old_str = new_str;
    while (repls(&new_str, old_str, (char *)sub, (char *)replace)) {
        free(old_str);
        old_str = new_str;
    }
    free(old_str);
    return new_str;
}


