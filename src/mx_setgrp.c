#include "uls.h"

char *mx_setgrp(struct stat *buff, e_flg *flag) {
    struct group *grp = getgrgid(buff->st_gid);
    char *grp_name = NULL;
    char *tmp = NULL;

    if (grp == NULL || flag[n]) {
        tmp = mx_itoa(buff->st_gid);
        grp_name = mx_strdup(tmp);
        free(tmp);
    }
    else
        grp_name = mx_strdup(grp->gr_name);
    return grp_name;
}
