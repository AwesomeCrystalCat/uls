#include "uls.h"
#include "stdio.h"

int mx_files_count(const char *name, e_flg *flag) {
    int count = 0;
    struct dirent *myfile;
    DIR *mydir;

    // printf("REMEMBER MY ... - %s\n", name);
    mydir = opendir(name);
        while((myfile = readdir(mydir)) != NULL) {
            // printf("files in dev - %s\n", myfile->d_name);
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
    // printf("count here - %d\n", count);
    return count;
}
