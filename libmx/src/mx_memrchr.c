#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    const unsigned char *str = s;
    str += n;

    while(*str != c && n > 0) {
        str--;
        n--;
    }
    if(*str == c) 
    return ((void*)(str));
        
    
    return  NULL;
}



