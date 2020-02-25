#ifndef HEADER_H
#define HEADER_H

typedef struct s_all {
    char **parsed;
} t_all;

#include "libmx/inc/libmx.h"

int main(int argc, char **argv);
void mx_parse_args(int n, char **str, t_all *ptr);

#endif
