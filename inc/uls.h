#ifndef ULS_H
#define ULS_H

#include "libmx.h"
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/ioctl.h>

typedef struct s_total {
    char *all_flags;
    int *arr_for_switch;
    int *priority;
    int num_of_flags; // в массиве входящих данных колличество аргументов с '-'
    int num_of_err;
    int num_of_files;
    int num_of_directs;
} t_total;

typedef struct s_arr_data {
    char ** files;
    char ** directs;
    char ** errors;
} t_data;

void mx_print_err(char *str);
void mx_swich_flags(int argc, char **argv, t_total *tot);

#endif

