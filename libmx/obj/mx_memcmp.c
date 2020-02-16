#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    unsigned char *q1 = (unsigned char *)s1;
    unsigned char *q2 = (unsigned char *)s2;
    
    if(q1 == q2 || n == 0) 
        return 0;
    for (size_t i = 0; i < n; i++) {
        if (q1[i] != q2[i]) {
        return ((int)q1[i] - q2[i]);
    }
} 
    return 0; 
}



