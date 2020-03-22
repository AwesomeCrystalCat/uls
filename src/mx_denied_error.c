#include "uls.h"

void mx_denied_error(t_elem **arr, int num, e_flg *flag) {
    if (flag[r_big])
        write(1, "\n", 1);
    write(2, "uls: ", 5);
    write(2, arr[num]->name, mx_strlen(arr[num]->name));
    write(2, ": Permission denied\n", 20);
}
