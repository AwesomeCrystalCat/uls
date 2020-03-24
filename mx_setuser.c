#include "uls.h"

char *mx_setuser(struct stat *buff, e_flg *flag) {
    struct passwd* pass = getpwuid(buff->st_uid);
    char *usr = NULL;
    char *tmp = NULL;

    if (pass == NULL || flag[n]) {
        tmp = mx_itoa(buff->st_uid);
        usr = mx_strdup(tmp);
        free(tmp);
    }
    else
        usr = mx_strdup(pass->pw_name);
    return usr;
}
