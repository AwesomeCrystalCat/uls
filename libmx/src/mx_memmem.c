#include "libmx.h"

 void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
 if (big_len - little_len < 0 || !big || !little || !little_len || !big_len)
     return NULL;

 unsigned char * str = (unsigned char *) big;
 unsigned char * ndl = (unsigned char *) little;
 size_t i = 0;
    while (i < big_len) {
        if ((big_len - i) > 0 && *str == *ndl) {
            if (mx_memcmp(str, ndl, little_len) == 0)
                return ((void*) str);
        }
        
        i++;
        str++;

    }
return NULL;
}


