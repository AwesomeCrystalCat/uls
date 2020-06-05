#include "uls.h"

void mx_print_fname(e_flg *flag, const char *name, int cur_dir) {
    if (mx_strcmp(name, ".") != 0 && cur_dir != -2) {
        if (cur_dir == 1)
            write(1, ".", 1);
        if (cur_dir == -1) {
            if (name[0] == '/')
                write(1, &name[1], mx_strlen(name) - 1);
            else
                write(1, name, mx_strlen(name));
        }
        else {
            if (name[0] == '/')
                write(1, name, mx_strlen(name));
            else {
                write(1, "/", 1);
                write(1, name, mx_strlen(name));
            }
        }
        write(1, ":\n", 2);
    }
}
