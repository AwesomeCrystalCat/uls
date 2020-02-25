#include "uls.h"
static void get_prior( e_flg *fl, int *value);
static void get_prior_m( e_flg *fl, int *value);
static void get_prior_t_and_size(e_flg *fl);
static void prior_1(int i, int j, char **argv, e_flg *fl);

void mx_prior_all(t_total *tot, e_flg *fl, char **argv) {
    for (int i = 1; i <= tot->count_dash; i++) {
        for (int j = 1; j < mx_strlen(argv[i]); j++) {
            prior_1(i, j, argv, fl);
        }
    }
}

static void prior_1(int i, int j, char **argv, e_flg *fl) {
    switch (argv[i][j]) {
        case '1':
            get_prior(fl, (int[]){1, 0, 0, 0});
            break;
        case 'C':
            get_prior(fl, (int[]){0, 1, 0, 0});
            break;
        case 'l':
            get_prior(fl, (int[]){0, 0, 1, 0});
            break;
        case 'x':
            get_prior(fl, (int[]){0, 0, 0, 1});
            break;
        case 'm':
            get_prior_m(fl, (int[]){0, 0, 0, 0, 1});
            break;
        case 't':
            get_prior_t_and_size(fl);
    }
}



static void get_prior( e_flg *fl, int *value) {
    fl[one] = value[0];
    fl[c_big] = value[1];
    fl[l]= value[2];
    fl[x] = value[3];
}

static void get_prior_m( e_flg *fl, int *value) {
    fl[one] = value[0];
    fl[c_big] = value[1];
    fl[l] = value[2];
    fl[x] = value[3];
    fl[m] = value[4];
}


static void get_prior_t_and_size(e_flg *fl) {
    if(fl[s_big] == 0)
        fl[t] = 1;
    else
        fl[t] = 0;

}


