#include "uls.h"

t_total *mx_read_data(int argc, char **argv, t_data *data) {
    t_total *tot = malloc(sizeof(t_total));
    char *our_flags = "@ACGRSTacegilmnoprstux1";
    tot->all_flags = our_flags;
    tot->size_all_fl = mx_strlen(tot->all_flags);
    e_flg *fl = malloc(tot->size_all_fl * sizeof(int));


//    for(int k = 0; k < tot->size_all_fl; k++) {
//        printf("%d", fl[k]);
//    }
    // printf("\n");
    mx_swich_flags(argc, argv, tot, fl);
    mx_prior_all(tot, fl, argv);

    // for(int j = 0; j < tot->size_all_fl; j++) {
        // printf("%d", fl[j]);
    // }
    return tot;
}


