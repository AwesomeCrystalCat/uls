#include "../inc/libmx.h"

char *mx_strnew(const int size) {
    char *new = (char *)malloc(sizeof(char) * (size + 1));

    if (new) {
        for (int i = 0; i <= size; i++) {
            new[i] = '\0';
        }
        return new;
    }
    return NULL;
}
