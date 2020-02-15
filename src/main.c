#include "uls.h"

static t_total *read_data(int argc, char **argv, t_data *data);
static t_data *data_init(int argc);

int main (int argc, char **argv) {
    t_data *data = data_init(argc);
    t_total *tot = read_data(argc, argv, data);
    return 0;

}


static t_data *data_init(int argc) {
    t_data *data = malloc(sizeof(t_data));
    data->errors = malloc(sizeof(argc));
    data->directs = malloc(sizeof(argc));
    data->files = malloc(sizeof(argc));
    return data;
}

static t_total *read_data(int argc, char **argv, t_data *data) {
    t_total *tot = malloc(sizeof(t_total));
    char *our_flags = "@ACGRSTacegilnoprsu1";
    tot->all_flags = our_flags;

    mx_swich_flags(argc, argv, tot);
    return tot;
}

