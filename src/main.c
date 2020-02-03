#include "header.h"
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

void uls(char nane[]);

int main (int argc, char *argv[]) {
    if (argc == 1)
        uls(".");
    else
        while(--argc) {
            printf("%s\n", *++argv);
            uls(*argv);
        }
}

void uls(char name[]) {
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
