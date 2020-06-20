#include "uls.h"

static void files_handling(t_data *data, e_flg *flag) {
    if (data->fcount != 0)
        mx_print_files(data, flag);
    if (data->dcount != 0 && data->fcount != 0)
        write(1, "\n", 1);
    if (data->dcount != 0)
        mx_print_dirs(data, flag);
}

int main (int argc, char **argv) {
    t_data *data = mx_data_init(argc);
    e_flg *flag = malloc(24 * sizeof(int));

    for (int j = 0; j < 24; j++)
        flag[j] = 0;
    mx_read_data(argc, argv, data, flag);
    mx_parse_args(argc, argv, data);
    if (data->dcount == 0 && data->fcount == 0
        && data->errors[0] == NULL) {
            data->cur_dir = 1;
            mx_dir_parse(flag, ".", data);
        }
    else
        files_handling(data, flag);
    if (data->errors[0] != NULL || data->ecount > 0)
        exit(1);
    return 0;
}
