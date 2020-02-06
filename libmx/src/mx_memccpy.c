#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c,
                                                             size_t n) {
    unsigned char *s = (unsigned char *) src;
    unsigned char *d = (unsigned char *) dst;
    size_t i = 0;
    if(n == 0)
        return NULL;
        for (; i < n && s[i] != c; i++)
            d[i] = s[i];
            if(s[i] == c) {
                d[i] = s[i];
                return &d[i + 1];
            }
            else 
                return NULL;
}




