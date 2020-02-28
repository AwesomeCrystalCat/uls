#include "uls.h"

char *mx_setuser(struct stat *buff, e_flg *flag) {
    struct passwd* pass = getpwuid(buff->st_uid);
    char *usr = NULL;

    if (pass == NULL || flag[o]) {
        usr = mx_strdup(mx_itoa(buff->st_uid));
    } 
    else {
        usr = mx_strdup(pass->pw_name);
    }
    return usr;
}
