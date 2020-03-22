#include "uls.h"

int mx_files_count(const char *name, e_flg *flag) {
    int count = 0;
    struct dirent *myfile;
    DIR *mydir;

    mydir = opendir(name);
        while((myfile = readdir(mydir)) != NULL) {
            if (flag[a])
                count++;
            else if (flag[a_big]) {
                if (!(strcmp(myfile->d_name, ".") == 0 || strcmp(myfile->d_name, "..") == 0))
                count++;
            }
            else {
                if (!(myfile->d_name[0] == '.' || mx_strcmp(myfile->d_name, ".") == 0 || mx_strcmp(myfile->d_name, "..") == 0))
                count++;
            }
        }
    closedir(mydir);
    return count;
}
