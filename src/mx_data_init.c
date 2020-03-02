#include "uls.h"

t_data *mx_data_init(int argc) {
    t_data *data = (t_data *)malloc(sizeof(t_data));
    data->files = (char **)malloc(sizeof(char) * argc);
    data->directs = (char **)malloc(sizeof(char) * argc);
    data->errors = (char **)malloc(sizeof(char) * argc);
    data->dcount = 0;
    data->fcount = 0;
    data->directs[0] = NULL;
    data->files[0] = NULL;
    data->errors[0] = NULL;
    return data;
}
