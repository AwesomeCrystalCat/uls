#include "uls.h"

static void illegal_fl(t_total *tot, int i, int j, char **argv) {
    char *illegal_flag = mx_strnew(1);

    illegal_flag[0] = argv[i][j];
    mx_print_err("uls: illegal option -- ");
    mx_print_err(illegal_flag);
    free(illegal_flag);
    mx_print_err("\n");
    mx_print_err("usage: uls [-");
    mx_print_err(tot->all_flags);
    mx_print_err("] [file ...]");
    mx_print_err("\n");
    exit(1);
}

static void my_switch(char **argv, int i, t_total *tot, e_flg *fl) {
    for (int j = 1; j < mx_strlen(argv[i]); j++) {
        bool test = false;

        for (int k = 0; k < tot->size_all_fl; k++) {
            if (argv[i][j] == tot->all_flags[k]) {
                fl[k] = 1;
                test = true;
            }
        }
        if (test == false)
            illegal_fl(tot, i, j, argv);
    }
}

void mx_swich_flags(int argc, char **argv, t_total *tot,  e_flg *fl) {
    tot->count_dash = 0;

    for (int i = 1; i < argc; i++) {
        struct stat buffer;

        if (lstat(argv[i], &buffer) == -1) {
            if (argv[i][0] != '-' || !argv[i][1])
                break;
            if (argv[i][1] == '-' && !argv[i][2]) {
                tot->count_dash++;
                break;
            }
            tot->count_dash++;
            my_switch(argv, i, tot, fl);
        }
    }
}
