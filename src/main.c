#include "uls.h"

int main (int argc, char **argv) {
    t_data *data = mx_data_init(argc);
    e_flg *flag = malloc(24 * sizeof(int));

    for (int j = 0; j < 24; j++)
        flag[j] = 0;
    t_total *tot = mx_read_data(argc, argv, data, flag);

    mx_parse_args(argc, argv, data);
    if (data->dcount == 0 && data->fcount == 0
        && data->errors[0] == NULL) {
        mx_dir_parse(flag, ".");
    }
    else {
        if (data->fcount != 0)
            mx_print_files(data, flag);
        if (data->dcount != 0 && data->fcount != 0)
            write(1, "\n", 1);
        if (data->dcount != 0)
            mx_print_dirs(data, flag);
    }
    system("leaks -q uls");
    //return 0;
}
