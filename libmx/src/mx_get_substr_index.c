#include "libmx.h"
char *mx_strstr(const char *haystack, const char *needle);
int mx_get_substr_index(const char *str, const char *sub) {

    if(!str || !sub)
        return -2;
    char * res = NULL;
    res = mx_strstr(str, sub);
    if(!res)
        return -1;
    int index = res - str;
    return index;
}


