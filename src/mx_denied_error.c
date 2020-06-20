#include "uls.h"

void mx_denied_error(t_elem **arr, int num, t_data *data) {
    write(2, "uls: ", 5);
    write(2, arr[num]->path, mx_strlen(arr[num]->path));
    write(2, ": Permission denied\n", 20);
    data->ecount++;
}
