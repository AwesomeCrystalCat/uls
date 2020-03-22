#include "uls.h"

static bool comparator(const char *name) {
    bool is_dir = 0;

    if (mx_strcmp(name, ".") == 0)
        is_dir = 1;
    if (mx_strcmp(name, "..") == 0)
        is_dir = 1;
    return is_dir;
}

int mx_files_count(const char *name, e_flg *flag) {
    int count = 0;
    struct dirent *myfile;
    DIR *mydir;

    mydir = opendir(name);
    while((myfile = readdir(mydir)) != NULL) {
        if (flag[a])
            count++;
        else if (flag[a_big]) {
            if (comparator(myfile->d_name) == 0)
                count++;
        }
        else {
            if (myfile->d_name[0] != '.'
                && comparator(myfile->d_name) == 0)
                count++;
        }
    }
    closedir(mydir);
    return count;
}
