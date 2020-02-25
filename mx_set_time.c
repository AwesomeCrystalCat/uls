#include "uls.h"

char* mx_set_time(struct stat *buff, t_elem *ptr, int flag, time_t time) {
    char* new_time;
    char* ftime = NULL;

    if (flag) {
        new_time = mx_strdup(ctime(&buff->st_atime));
        ptr->ctime = mx_strndup(new_time + 4, 12);
        ftime = mx_strndup(new_time + 4, 6);
    }
    else {
        new_time = mx_strdup(ctime(&buff->st_mtime));
        ptr->ctime = mx_strndup(new_time + 4, 12);
        ftime = mx_strndup(new_time + 4, 6);
    }
    return ftime;
}
