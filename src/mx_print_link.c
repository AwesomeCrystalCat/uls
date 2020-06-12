#include "uls.h"

void mx_print_link(t_elem **arr, int j) {
    char linkbuf[1024];
    int len = readlink(arr[j]->path, linkbuf, sizeof linkbuf);

    linkbuf[len] = '\0';
    mx_printstr(" -> ");
    mx_printstr(linkbuf);
}
