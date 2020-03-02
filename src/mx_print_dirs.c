#include "uls.h"
#include <stdio.h> 

void mx_print_dirs(t_data *data, e_flg *flag) {
    for (int i = 0; data->directs[i] != NULL; i++) {
        mx_dir_parse(flag, data->directs[i]);
    }
}
