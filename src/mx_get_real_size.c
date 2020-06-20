#include "uls.h"

static char *count_minor(char *minor, int l_min) {
    char *buf = NULL;

    if (l_min < 4) {
        for (int i = 0; i < 4 - l_min; i++) {
            buf = mx_strjoin(" ", minor);
            free(minor);
            minor = buf;
        }
    }
    else {
        free(minor);
        minor = mx_strdup("   0");
    }
    return minor;
}
static char *count_major(char *major, int l_maj) {
    char *buf = NULL;

    if (l_maj < 2) {
        for (int i = 0; i < 3 - l_maj; i++) {
            buf = mx_strjoin(" ", major);
            free(major);
            major = buf;
        }
    }
    buf = mx_strjoin(major, ",");
    free(major);
    return buf;
}

static char *lets_concat(char *major, char *minor, int l_maj, int l_min) {
    char *buf = NULL;

    minor = count_minor(minor, l_min);
    major = count_major(major, l_maj);
    buf = mx_strjoin(major, minor);
    free(major);
    free(minor);
    return buf;
}

char *mx_get_real_size(struct stat *buff, char *mode,
                       int l_min, int l_maj) {
    char *res = NULL;
    char *minor = NULL;
    char *major = NULL;

    if (mode[0] != 'l' && mode[0] != 'd' && mode[0] != '-'
        && buff->st_size == 0 && mode[0] != 's') {
        major = mx_itoa(MX_MAJOR(buff->st_rdev));
        l_maj = mx_strlen(major);
        minor = mx_itoa(MX_MINOR(buff->st_rdev));
        l_min = mx_strlen(minor);
        res = lets_concat(major, minor, l_maj, l_min);
    }
    else 
        res = mx_itoa(buff->st_size);
    return res;
}
