#include "uls.h"

void mx_print_fname(e_flg *flag, const char *name) {
    if (mx_strcmp(name, ".") != 0) {
        write(1, "./", 2);
        if (name[0] == '/')
        write(1, name, mx_strlen(name));
        write(1, ":\n", 2);
    }
}
