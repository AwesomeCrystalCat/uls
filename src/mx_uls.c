#include "uls.h"

void mx_uls(char name[]) {
    DIR *dir_ptr;
    struct dirent *direntp;

    if((dir_ptr = opendir(name)) == NULL) {
        write(2, "uls:can't open ", 15);
        write(2, name, strlen(name));
    }
    else {
        while((direntp = readdir(dir_ptr)) != NULL) {
            write(1, direntp->d_name, strlen(direntp->d_name));
            write(1, "\n", 2);
        }
        closedir(dir_ptr);
    }
}
