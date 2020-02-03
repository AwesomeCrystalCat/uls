#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int i = 0;

    while (src[i] != '\0' && len > i) {
        dst[i] = src[i];
        i++;
    }
    while (len > i) {
        dst[i] = '\0';
        i++;
    }
    return dst;
}
