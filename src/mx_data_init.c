#include "uls.h"

t_data *mx_data_init(int argc) {
    t_data *data = (t_data *)malloc(sizeof(t_data));

    data->directs = (char **)malloc(sizeof(char) * argc);
    data->files = (char **)malloc(sizeof(char) * argc);
    data->errors = (char **)malloc(sizeof(char) * argc);
    data->dcount = 0;
    data->fcount = 0;
    data->errors[0] = NULL;
    data->ecount = 0;
    data->cur_dir = 0;
    return data;
}
