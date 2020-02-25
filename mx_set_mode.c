#include "uls.h"

static char getChar(int mode, int is_exec, int is_id) {
    if (mode & is_exec) {
        if (mode & is_id)
            return 's';
        else
            return 'x';
    }
    else {
        if (mode & is_id)
            return 'S';
        else
            return '-';
    }
}

static char getMode(int mode, int user_type) {
    if (user_type == 1)
        return getChar(mode, 0000100, 0004000);
    else if (user_type == 2)
        return getChar(mode, 0000010, 0002000);
    else {
        if (mode & 0000001) {
            if (mode & 0001000)
                return 't';
            else
                return 'x';
        }
        else {
            if (mode & 0001000)
                return 'T';
            else 
                return '-';
        }
    }
}

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
    str[3] = getMode(buff->st_mode, 1);
    str[4] = (val & S_IRGRP) ? 'r' : '-';
    str[5] = (val & S_IWGRP) ? 'w' : '-';
    str[6] = getMode(buff->st_mode, 2);
    str[7] = (val & S_IROTH) ? 'r' : '-';
    str[8] = (val & S_IWOTH) ? 'w' : '-';
    str[9] = getMode(buff->st_mode, 4);
    return str;
}
