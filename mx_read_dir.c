#include "uls.h"
#include <stdio.h>

void mx_read_dir(t_elem **dir_args, const char *str, int flag_a, int flag_A) {
    struct dirent *dirptr;
    DIR *ddir;
    int i = 0;

    ddir = opendir(str);
    while((dirptr = readdir(ddir)) != NULL) {
        if (flag_a)
            dir_args[i++] = mx_getstats(dirptr->d_name);
        else if (flag_A) {
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
