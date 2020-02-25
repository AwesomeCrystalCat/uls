#include "uls.h"
#include "stdio.h"

int mx_files_count(const char *name, int flag_a, int flag_A) {
    int count = 0;
    struct dirent *myfile;
    DIR *mydir;

    mydir = opendir(name);
        while((myfile = readdir(mydir)) != NULL) {
            if (flag_a)
                count++;
            else if (flag_A) {
                if (!(strcmp(myfile->d_name, ".") == 0 || strcmp(myfile->d_name, "..") == 0))
                count++;
            }
            else {
                if (!(myfile->d_name[0] == '.' || mx_strcmp(myfile->d_name, ".") == 0 || mx_strcmp(myfile->d_name, "..") == 0))
                count++;
            }
        }
    closedir(mydir);
    // printf("next folder - %d\n", count);
    return count;
}
