#include "uls.h"

void mx_denied_error(t_elem **arr, int num, e_flg *flag) {
    if (flag[r_big])
        write(1, "\n", 1);
    write(1, "uls: ", 5);
    write(1, arr[num]->name, mx_strlen(arr[num]->name));
    write(1, ": Permission denied\n", 20);
}
