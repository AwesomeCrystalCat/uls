#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    unsigned char *d = (unsigned char *)dst;
    unsigned char *s = (unsigned char *)src;
    for (size_t i = 0; i < n; i++)
        d[i] = s[i];
    return dst;
}   



