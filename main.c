#include "uls.h"
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/acl.h>
#include <stdlib.h>

int main (int argc, char **argv) {
    t_data *data = mx_data_init(argc);
    e_flg *flag = malloc(24 * sizeof(int));
    for (int j = 0; j < 24; j++)
        flag[j] = 0;
    t_total *tot = mx_read_data(argc, argv, data, flag);

    mx_parse_args(argc, argv, data);
    if (data->directs[0] == NULL && data->files[0] == NULL && data->errors[0] == NULL) {
        mx_dir_parse(flag, ".");
    }
    else {
        printf("HERE\n");
        mx_print_files(data, flag);
        if (data->files[0] != NULL)
            write(1, "\n", 1);
        mx_print_dirs(data, flag);
    }
    return 0;
}
