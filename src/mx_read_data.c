#include "uls.h"

void mx_read_data(int argc, char **argv, t_data *data, e_flg *fl) {
    t_total *tot = malloc(sizeof(t_total));
    char *our_flags = "@ACGRSTacefgilmnoprstux1";

    tot->all_flags = our_flags;
    tot->size_all_fl = mx_strlen(tot->all_flags);
    mx_swich_flags(argc, argv, tot, fl);
    mx_prior_all(tot, fl, argv);
    mx_errors_arr(tot, data, argc, argv);
    mx_print_errors(data);
    free(tot);
}
