#include "uls.h"

void mx_print_errors(t_data *data) {
    char *str_err = NULL;
    char *tmp = NULL;

    if (data->errors != NULL) {
        for (int i = 0; data->errors[i] != NULL; i++) {
            DIR *dir_ptr = opendir(data->errors[i]);

            if (dir_ptr == NULL)
                tmp = mx_strnew(1);
            str_err = mx_strjoin(tmp, "uls: ");
            free(tmp);
            tmp = (mx_strjoin(str_err, data->errors[i]));
            perror(tmp);
            free(str_err);
            free(tmp);
        }
    }
}
