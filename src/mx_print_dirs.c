#include "uls.h"
#include <stdio.h> 

void mx_print_dirs(t_data *data, e_flg *flag) {
    struct stat buff;
    char *mode = (char *)malloc(sizeof(char) * 10);

    for (int i = 0; data->directs[i] != NULL; i++) {
        lstat(data->directs[i], &buff);
        mode = mx_set_mode(&buff);
        if (mode[1] != '-' && mode[4] != '-' && mode[7] != '-')
            mx_dir_parse(flag, data->directs[i]);
        else {
            write(1, "uls: ", 5);
            write(1, data->directs[i], mx_strlen(data->directs[i]));
            write(1, ": Permission denied\n", 20);
        }
    }
}
