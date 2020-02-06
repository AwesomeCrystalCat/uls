#include "libmx.h"
#include <stdlib.h>
char *mx_strnew(const int size) {
    if (size < 0) return NULL;

    char *t = (char*) malloc((size + 1)* sizeof(char));
    if (!t) 
        return 0;
   
    for (int i = 0; i < size + 1; i++)
        t[i] = '\0';

        return t;
}


