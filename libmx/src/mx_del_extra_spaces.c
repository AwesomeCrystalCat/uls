#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
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
    char *s = start;
    while(s <= finish) {
        len++;
        if (mx_isspace(*s) == 1) {
            while(mx_isspace(*s) == 1)
            s++;
        }
        else
            s++;
    } 
    char *res = mx_strnew(len);
    char *r = res;
    s = start;
    while(s <= finish) {
       *r = *s;
        if (mx_isspace(*s) == 1) {
            while(mx_isspace(*s) == 1)
                s++;
        }
        else 
            s++;
        r++;
    }
    return res;
}

