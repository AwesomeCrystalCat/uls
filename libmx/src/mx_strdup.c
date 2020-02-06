#include "libmx.h"

char *mx_strdup(const char *str) {
    if(!str)
        return NULL;
        
    char *t = mx_strnew(mx_strlen(str));
    if(t) {
        mx_strcpy(t, str);
    }

    return t;
}






