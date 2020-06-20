#include "uls.h"

void mx_printer(t_elem **dir_args, t_all *ptr, e_flg *flag) {
    if (flag[l])
        mx_output_l(dir_args, ptr, flag);
    else if (flag[m])
        mx_output_m(dir_args, ptr, flag);
    else if (flag[one])
        mx_output_1(dir_args, ptr, flag, 0);
    else if (flag[x])
        mx_output_x(dir_args, ptr, flag, 0);
    else
        mx_output_c(dir_args, ptr, flag, 0);
    write(1, "\n", 1);
}
