#include "uls.h"

//simple parser for work

void mx_parse_args(int n, char **str, t_all *ptr) {
    ptr->parsed = (char **)malloc(sizeof(char *) * n);
    int i = 1;
    int j = 0;

    ptr->parsed[n - 1] = NULL;
    while (i < n) {
        ptr->parsed[j] = (char *)malloc(sizeof(char) * mx_strlen(str[i]) + 1);
        ptr->parsed[j] = mx_strdup(str[i]);
        i++; j++;
    }
}
