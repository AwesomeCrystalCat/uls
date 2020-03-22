#include "uls.h"

void mx_errors_arr(t_total *tot, t_data *data, int argc, char **argv) {
    int count = 0;

    for (int i = tot->count_dash + 1; i < argc; i++) {
        struct stat buffer;

        if (lstat(argv[i], &buffer) == -1) {
            data->errors[count] = argv[i];
            count++;
        }
        data->errors[count] = NULL;
    }
}
