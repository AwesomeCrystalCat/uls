#include "uls.h"
#include <stdio.h>

void mx_read_dir(t_elem **dir_args, const char *str, e_flg *flag) {
    struct dirent *dirptr;
    DIR *ddir;
    int i = 0;

    ddir = opendir(str);
    while((dirptr = readdir(ddir)) != NULL) {
        if (flag[a])
            dir_args[i++] = mx_getstats(dirptr->d_name);
        else if (flag[a_big]) {
            if (!(mx_strcmp(dirptr->d_name, ".") == 0 || mx_strcmp(dirptr->d_name, "..") == 0)) {
                dir_args[i++] = mx_getstats(dirptr->d_name);
            }
        }
        else {
            if (!(dirptr->d_name[0] == '.' || mx_strcmp(dirptr->d_name, ".") == 0 || mx_strcmp(dirptr->d_name, "..") == 0))
                dir_args[i++] = mx_getstats(dirptr->d_name);
        }   
    }
}
