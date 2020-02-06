#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    if (!needle || !haystack) return NULL;
    char *ndl = !needle ? NULL : (char *)needle;
    char *str = (char *) haystack;
    size_t len = mx_strlen(needle);
    while(*str != '\0') {
        if (*str  == *ndl) {
            if (mx_strncmp(str, ndl, len) == 0)
            return (str);
        }
        str++;
    }
    return NULL;
}


