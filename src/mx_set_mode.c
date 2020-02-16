#include "uls.h"

char set_file_type(struct stat *buff) {
    char chr;

    switch (buff->st_mode & S_IFMT) {
           case S_IFBLK: chr = 'b';
           break;
           case S_IFCHR: chr = 'c';
           break;
           case S_IFDIR: chr = 'd';
           break;
           case S_IFIFO: chr = 'p';
           break;
           case S_IFLNK: chr = 'l';
           break;
           case S_IFREG: chr = '-';
           break;
           case S_IFSOCK: chr = 's';
           break;
           }
    return chr;
}

char *mx_set_mode(struct stat *buff) { //add permission mode s and t
    char *str = mx_strnew(10);
    int val = (buff->st_mode & ~S_IFMT);
    str[0] = set_file_type(buff);
    str[1] = (val & S_IRUSR) ? 'r' : '-';
    str[2] = (val & S_IWUSR) ? 'w' : '-';    
    str[3] = (val & S_IXUSR) ? 'x' : '-';
    str[4] = (val & S_IRGRP) ? 'r' : '-';
    str[5] = (val & S_IWGRP) ? 'w' : '-';
    str[6] = (val & S_IXGRP) ? 'x' : '-';
    str[7] = (val & S_IROTH) ? 'r' : '-';
    str[8] = (val & S_IWOTH) ? 'w' : '-';
    str[9] = (val & S_IXOTH) ? 'x' : '-';
    return str;
}
