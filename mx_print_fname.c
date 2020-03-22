#include "uls.h"

void mx_print_fname(e_flg *flag, const char *name) {
    write(1, name, mx_strlen(name));
    write(1, ":\n", 2);
}
