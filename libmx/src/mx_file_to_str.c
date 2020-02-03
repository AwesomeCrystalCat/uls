#include "../inc/libmx.h"

static int malloc_file(const char *file) {
    int fp = open(file, O_RDONLY);
    char c;
    int i = 0;

    while (read(fp,&c,1))
        i++;
    close(fp);
    return i;
}

char *mx_file_to_str(const char *file) {
    int fp = open(file, O_RDONLY);
    char c;
    int i = 0;

    if (read(fp, (void *)0, 0) < 0)
        return NULL;
    if (fp == -1)
        return NULL;
    char *s = mx_strnew(malloc_file(file));
    while (read(fp, &c, 1))
        s[i++] = c;
    s[i] = '\0';
    close(fp);
    return s;
}
