#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int j = 0;
    if (!dst || !src) 
        return NULL;
    if (len == 0)
        return 0;
    
    while (j < len) {
		dst[j] = src[j];
		j++;
	}
    return dst;
}




