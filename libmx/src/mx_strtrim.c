#include "libmx.h"

char *mx_strtrim(const char *str) {
    if(!str) return NULL;
    int len = mx_strlen(str);
    if (len == 0) 
        return mx_strnew(0);
    
    char *start = (char *)str;
    char *finish = (char *)str +(len - 1);
    while(mx_isspace(*start) == 1)
        start++;
    while(finish > start && mx_isspace(*finish) == 1)
        finish--;
    if(start == finish) return mx_strnew(0);
    char * new = mx_strndup(start, (finish - start) + 1);
    if (!new) return NULL;
    return new;
}



