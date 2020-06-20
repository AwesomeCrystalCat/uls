#include "uls.h"

static bool comparator(const char *name) {
    bool is_dir = 0;

    if (mx_strcmp(name, ".") == 0)
        is_dir = 1;
    if (mx_strcmp(name, "..") == 0)
        is_dir = 1;
    return is_dir;
}

void mx_read_dir(t_elem **dir_args, const char *str, e_flg *flag) {
    struct dirent *dirptr;
    DIR *ddir;
    int i = 0;

    if ((ddir = opendir(str)) != NULL) {
        while((dirptr = readdir(ddir)) != NULL) {
            if (flag[a])
                dir_args[i++] = mx_getstats(dirptr->d_name, str, flag);
            else if (flag[a_big]) {
                if (comparator(dirptr->d_name) == 0)
                    dir_args[i++] = mx_getstats(dirptr->d_name, str, flag);
            }
            else {
                if (dirptr->d_name[0] != '.'
                    && comparator(dirptr->d_name) == 0)
                    dir_args[i++] = mx_getstats(dirptr->d_name, str, flag);
            }
        }
        closedir(ddir);
    }
}
