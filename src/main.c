#include "uls.h"


void mx_uls(char nane[]);

int main (int argc, char *argv[]) {
    if (argc == 1)
        mx_uls(".");
    else
        while(--argc) {
            printf("%s\n", *++argv);
            mx_uls(*argv);
        }
}




