#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    
        char *dst = s1;
        char *src = (char*)s2;
        while(*dst != '\0') 
            dst++;
        
        while(*src != '\0') 
            *dst++ = *src++;
        
        *dst = '\0';
        return dst;
}



