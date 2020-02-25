#include "uls.h"

void mx_print_errors(t_data *data) {
    char *str_err = NULL;

    if(data->errors != NULL)
        for(int i = 0; data->errors[i] != NULL; i++) {
            DIR *dir_ptr = opendir(data->errors[i]);
            if (dir_ptr == NULL)
                str_err = mx_strnew(1);
                str_err = mx_strjoin(str_err, "uls: ");
                str_err = (mx_strjoin(str_err, data->errors[i]));
                perror(str_err);
        }
}
