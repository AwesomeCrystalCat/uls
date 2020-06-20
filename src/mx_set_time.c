#include "uls.h"

static void time_end(t_elem *ptr, e_flg *flag, char *new, char *sec) {
    char *tmp = NULL;

    if (time(0) - ptr->u_time > 15713490) {
        tmp = mx_strndup(new + 4, 7);
        sec = mx_strndup(new + 19, 5);
        ptr->r_time = mx_strjoin(tmp, sec);
        free(sec);
        free(tmp);
    }
    else if (flag[t_big])
        ptr->r_time = mx_strndup(new + 4, 20);
    else
        ptr->r_time = mx_strndup(new + 4, 12);
    sec = mx_itoa(ptr->u_time);
    ptr->f_time = mx_strjoin(sec, ptr->name);
    free(new);
    free(sec);
}

void mx_set_time(struct stat *buff, t_elem *ptr, e_flg *flag) {
    char *new = NULL;
    char *sec = NULL;

    if (flag[u]) {
        ptr->u_time = buff->st_atime;
        sec = ctime(&buff->st_atime);
        new = mx_strdup(sec);
    }
    else {
        ptr->u_time = buff->st_mtime;
        sec = ctime(&buff->st_mtime);
        new = mx_strdup(sec);
    }
    time_end(ptr, flag, new, sec);
}
