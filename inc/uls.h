#ifndef ULS_H
#define ULS_H

typedef struct s_all {
    char **parsed;
} t_all;

typedef struct s_total {
    char *argv_to_str;
    int len_argv;
    int *flg;
} t_total;

typedef enum e_fl {
    R,
    a,
    A,
    G,
    h,
    dog,
    e,
    T,
    one,
    C,
    r, //revers;
    t, //time;
    u, //user;
    c,
    S //size (bytes);
} e_flags;

typedef enum e_err {
    illegal_option,
    no_such_file_or_directory //с большой буквы!!!
    //empty directory ???? это в поток ошибок?

} e_errors;

#include "libmx/inc/libmx.h"
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv);
void mx_parse_args(int n, char **str, t_all *ptr);
void mx_uls(char name[]);
void mx_read_flags(t_total *tot, char ** argv);
void mx_print_error(t_total *tot, e_errors err);

#endif
