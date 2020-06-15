#include "uls.h"

static void print_name(int i, t_elem **arr, t_data *data) {
    if (mx_strcmp(arr[i]->name, ".") != 0) {
        mx_print_fname(arr[i]->path, 0);
        mx_denied_error(arr, i, data);
    }
}

void mx_check_perm(t_elem **arr, int i, e_flg *flag, t_data *data) {
    write(1, "\n", 1);
    if (data->cur_dir == -2)
        data->cur_dir = 0;
    if (arr[i]->mode[1] == 'r'
        && (mx_strcmp(arr[i]->uid, "mtararuiev") == 0))
        mx_dir_parse(flag, arr[i]->path, data);
    else if (arr[i]->mode[4] == 'r' && arr[i]->mode[7] == 'r')
        mx_dir_parse(flag, arr[i]->path, data);
    else
        print_name(i, arr, data);
}
