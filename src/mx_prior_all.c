#include "uls.h"

static void get_prior_2(int i, int j, char **argv, e_flg *fl);
static void get_prior_1(int i, int j, char **argv, e_flg *fl);
static void prior_1(e_flg *fl, int *value);
static void prior_2(e_flg *fl, int *value);

void mx_prior_all(t_total *tot, e_flg *fl, char **argv) {
    for (int i = 1; i <= tot->count_dash; i++)
        for (int j = 1; j < mx_strlen(argv[i]); j++) {
            get_prior_1(i, j, argv, fl);
            get_prior_2(i, j, argv, fl);
            switch (argv[i][j]) {
                case 'm':
                    prior_1(fl, (int[]) {0, 0, 0, 0, 1, 0, 0, 0});
                    break;
                case 'g':
                    prior_1(fl, (int[]) {0, 0, 1, 0, 0, 1, 0, 0});
                    break;
                case 'n':
                    prior_1(fl, (int[]) {0, 0, 1, 0, 0, 0, 1, 0});
                    break;
                case 'o':
                    prior_1(fl, (int[]) {0, 0, 1, 0, 0, 0, 0, 1});
                    break;
            }
        }
}

static void get_prior_1(int i, int j, char **argv, e_flg *fl) {
    switch (argv[i][j]) {
        case '1':
            prior_1(fl, (int[]) {1, 0, 0, 0, 0, 0, 0, 0});
            break;
        case 'C':
            prior_1(fl, (int[]) {0, 1, 0, 0, 0, 0, 0, 0});
            break;
        case 'l':
            prior_1(fl, (int[]) {0, 0, 1, 0, 0, 0, 0, 0});
            break;
        case 'x':
            prior_1(fl, (int[]) {0, 0, 0, 1, 0, 0, 0, 0});
            break;
        case 'c':
            if(fl[t] == 1 || fl[s_big] == 1)
                fl[c] = 0;
            break;
    }
}

static void prior_1(e_flg *fl, int *value) {
    fl[one] = value[0];
    fl[c_big] = value[1];
    fl[l]= value[2];
    fl[x] = value[3];
    fl[m] = value[4];
    fl[g] = value[5];
    fl[n] = value[6];
    fl[o] = value[7];
}

static void get_prior_2(int i, int j, char **argv, e_flg *fl) {
    switch (argv[i][j]) {
        case 't':
            if(fl[s_big] == 1)
            fl[t] = 0;
            break;
        case '@':
            if (!fl[l])
                fl[dog] = 0;
            break;
        case 'f':
            fl[a] = 1;
            prior_2(fl, (int[]){0, 0, 0, 0, 0});
            break;
        case 'S':
            fl[t] = 0;
            fl[c] = 0;
            fl[u] = 0;
            break;
    }
}

static void prior_2(e_flg *fl, int *value) {
    fl[s_big] = value[0];
    fl[t] = value[1];
    fl[c] = value[2];
    fl[r] = value[3];
    fl[u] = value[4];
}
