#include "uls.h"

static void malloc_array_flags(t_total *tot);
static void my_switch(char **argv, int i, t_total *tot);
static void illegal_fl(t_total *tot, int i, int j, char **argv);

void mx_swich_flags(int argc, char **argv, t_total *tot) {
    int count = 0;
    malloc_array_flags(tot);

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-' || !argv[i][1]) // нет флагов
            break;
        if (argv[i][1] == '-' && !argv[i][2]) {  // "--"
            count++;
            break;
        }
        count++;
        my_switch(argv, i,tot);
    }
    for (int l = 0; l < 20; l++ ) {
        printf("%d", tot->arr_for_switch[l]);
    }
    printf("\n");
}


static void malloc_array_flags(t_total *tot) {
    int len = mx_strlen(tot->all_flags);
    tot->arr_for_switch = malloc(sizeof(int) * len);

    for (int i = 0; i < len ; i++ ) {
        tot->arr_for_switch[i] = 0;
    }
}


static void my_switch(char **argv, int i, t_total *tot) {
    for (int j = 1; j < mx_strlen(argv[i]); j++) {
        bool test = false;

        for (int k = 0; k < mx_strlen(tot->all_flags); k++) {
            if (argv[i][j] == tot->all_flags[k]) {
                tot->arr_for_switch[k] = 1;
                test = true;
            }

        }
        if (test == false)
            illegal_fl(tot->all_flags, i, j, argv);
    }
}


static void illegal_fl(t_total *tot, int i, int j, char **argv) {
    char *illegal_flag = mx_strnew(1);
    illegal_flag[0] = argv[i][j];

    mx_print_err("uls: illegal option -- ");
    mx_print_err(illegal_flag);
    mx_print_err("\n");
   // exit(1);
}