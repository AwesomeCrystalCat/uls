#include "uls.h"

char *mx_setgrp(struct stat *buff, e_flg *flag) {
    struct group *grp = getgrgid(buff->st_gid);
    char *grp_name = NULL;

    if (grp == NULL || flag[g]) {
        grp_name = mx_strdup(mx_itoa(buff->st_gid));
    } 
    else {
        grp_name = mx_strdup(grp->gr_name);
    }
    return grp_name;
}
