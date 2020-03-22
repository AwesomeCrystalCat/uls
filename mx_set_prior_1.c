#include "uls.h"

void mx_set_prior_1(e_flg *fl, int *value) {
    fl[one] = value[0];
    fl[c_big] = value[1];
    fl[l] = value[2];
    fl[x] = value[3];
    fl[m] = value[4];
    fl[g] = value[5];
    fl[n] = value[6];
    fl[o] = value[7];
}
