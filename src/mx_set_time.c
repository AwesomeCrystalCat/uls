#include "uls.h"

void mx_set_time(struct stat *buff, t_elem *ptr, e_flg *flag) {
    char* new_time = NULL;

    if (flag[u]) {
        ptr->u_time = buff->st_atime;
        new_time = mx_strdup(ctime(&buff->st_atime));
    }
    else {
        ptr->u_time = buff->st_mtime;
        new_time = mx_strdup(ctime(&buff->st_mtime));
    }
    if (time(0) - ptr->u_time > 15552000) {
        ptr->r_time = mx_strndup(new_time + 4, 7);
        ptr->r_time = mx_strjoin(ptr->r_time, mx_strndup(new_time + 19, 5));
    }
    else if (flag[t_big])
        ptr->r_time = mx_strndup(new_time + 4, 20);
    else
        ptr->r_time = mx_strndup(new_time + 4, 12);
    ptr->f_time = mx_strjoin(mx_itoa(ptr->u_time), ptr->name);
}

