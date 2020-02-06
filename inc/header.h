#ifndef ULS
#define ULS

#include "libmx/inc/libmx.h"

#include "libmx.h"
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

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

void mx_uls(char name[]);
void mx_read_flags(t_total *tot, char ** argv);
void mx_print_error(t_total *tot, e_errors err);


#endif

