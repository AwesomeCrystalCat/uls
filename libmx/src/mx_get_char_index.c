#include "libmx.h"

int mx_get_char_index(const char *str, char c) {
    if(!str) return -2;
    int index = 0;

    for(; str[index] != c  && str[index] != '\0' ; index++); 

    if (str[index] == c)
        return index;
    else
        return -1;
        
}

