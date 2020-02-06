#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {

    if (s1 == NULL || s2 == NULL) {
        if (s1 == NULL)
            return mx_strdup(s2);
        else 
            return mx_strdup(s1);
    }

    if(s1 == NULL && s2 == NULL)  
            return NULL;
    int len = mx_strlen(s1) + mx_strlen(s2);
    char * new =  mx_strnew(len);
        if (!new) return NULL;
    mx_strcpy(new, s1);
    mx_strcat(new, s2);
        return new;
}



