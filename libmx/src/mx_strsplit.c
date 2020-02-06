#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    if(!s) return NULL;
    int len = mx_strlen(s);
    if (len == 0) 
        return NULL;
    char *start = (char *)s;
    char *finish = (char *)s +(len - 1);
    while(*start == c)
        start++;
    while(finish > start && *finish == c)
        finish--;
    if(start == finish) return NULL;
    char *str = start; // first word
    int count = mx_count_words(s, c); //how mach words
    char **arr = (char **) malloc(sizeof(char*) * (count + 1)); //for y;
    int i = 0;
    while(str <= finish) {
        arr[i] = mx_strndup(str, mx_len_to_delim(str, c)); //for x;
        while(*str && *str != c) // skip (before the next word)
            str++;
        while(*str && *str == c) 
            str++;
        i++;
    } 
    arr[i] = NULL;
    return (arr);
}




