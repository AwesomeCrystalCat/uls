#include "uls.h"

t_data *mx_data_init(int argc) {
    t_data *data = malloc(sizeof(t_data));

    data->errors = malloc(sizeof(argc));
    data->directs = malloc(sizeof(argc));
    data->files = malloc(sizeof(argc));
    data->files[0] = NULL;
    data->directs[0] = NULL;
    data->fcount = 0;
    data->dcount = 0;
    return data;
}