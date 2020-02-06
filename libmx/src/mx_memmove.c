#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    unsigned char * s = (unsigned char*)src;     
    unsigned char *d = (unsigned char*)dst;
    size_t i = 0;
    if(!src && !dst)
        return NULL;
    if ((s < d) && (s - 1 + len) > d) {
        s = s + len - 1;
        d = d + len - 1;
            while(len-- > 0) {
                *d-- = *s--;
            }
    }
    else {
        while (i < len) {
        d[i] = s[i];
        i++;
        }
    }
    return d;
}




