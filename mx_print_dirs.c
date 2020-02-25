#include "uls.h"
#include <stdio.h> 

void mx_print_dirs(t_data *data) {
    for (int i = 0; data->directs[i] != NULL; i++) {
        mx_dir_parse(0, data->directs[i]);
    }
}
