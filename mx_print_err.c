#include "uls.h"

void mx_print_err(char *str) {
    write(2, str, mx_strlen(str));
}
