#include "uls.h"

static char get_sticky(int mode, int is_exec, int is_id) {
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

static char set_access_mode(int mode, int user_type) {
    if (user_type == 1)
        return get_sticky(mode, MX_IXUSR, MX_ISUID);
    else if (user_type == 2)
        return get_sticky(mode, MX_IXGRP, MX_ISGID);
    else {
        if (mode & MX_IXOTH) {
            if (mode & MX_ISVTX)
                return 't';
            else
                return 'x';
        }
        else {
            if (mode & MX_ISVTX)
                return 'T';
            else 
                return '-';
        }
    }
}

static char set_file_type(struct stat *buff) {
    char chr;

    switch (buff->st_mode & MX_IFMT) {
           case MX_IFBLK: chr = 'b';
           break;
           case MX_IFCHR: chr = 'c';
           break;
           case MX_IFDIR: chr = 'd';
           break;
           case MX_IFIFO: chr = 'p';
           break;
           case MX_IFLNK: chr = 'l';
           break;
           case MX_IFREG: chr = '-';
           break;
           case MX_IFSOCK: chr = 's';
           break;
           }
    return chr;
}

char *mx_set_mode(struct stat *buff) { //add permission mode s and t
    char *str = mx_strnew(10);
    int val = (buff->st_mode & ~MX_IFMT);
    str[0] = set_file_type(buff);
    str[1] = (val & MX_IRUSR) ? 'r' : '-';
    str[2] = (val & MX_IWUSR) ? 'w' : '-';  
    str[3] = set_access_mode(buff->st_mode, 1);
    str[4] = (val & MX_IRGRP) ? 'r' : '-';
    str[5] = (val & MX_IWGRP) ? 'w' : '-';
    str[6] = set_access_mode(buff->st_mode, 2);
    str[7] = (val & MX_IROTH) ? 'r' : '-';
    str[8] = (val & MX_IWOTH) ? 'w' : '-';
    str[9] = set_access_mode(buff->st_mode, 4);
    return str;
}
