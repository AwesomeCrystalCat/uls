#include "uls.h"
#include <stdio.h>

void putstr(const char *str, int fd)
{
    int len = mx_strlen(str);
    write(fd, str, len);
}

void mx_print_colored(const char *name, const char *path) {
    struct stat buff;

    lstat(path, &buff);
    if ((buff.st_mode & S_IFMT) == S_IFDIR) {
           putstr(MX_DIR_COL, 1);
           putstr(name, 1);
           putstr(MX_NONE_COL, 1);
    }
    if ((buff.st_mode & S_IFMT) == S_IFBLK) {
           putstr(MX_BLK_COL, 1);
           putstr(name, 1);
           putstr(MX_NONE_COL, 1);
    }
    if ((buff.st_mode & S_IFMT) == S_IFCHR) {
           putstr(MX_CHR_COL, 1);
           putstr(name, 1);
           putstr(MX_NONE_COL, 1);
    }
    if ((buff.st_mode & S_IFMT) == S_IFIFO) {
           putstr(MX_FIFO_COL, 1);
           putstr(name, 1);
           putstr(MX_NONE_COL, 1);
    }
    if ((buff.st_mode & S_IFMT) == S_IFLNK) {
           putstr(MX_LNK_COL, 1);
           putstr(name, 1);
           putstr(MX_NONE_COL, 1);
    }
    if ((buff.st_mode & S_IFMT) == S_IFREG) {
           putstr(MX_REG_COL, 1);
           putstr(name, 1);
           putstr(MX_NONE_COL, 1);
    }
    if ((buff.st_mode & S_IFMT) == S_IFSOCK) {
           putstr(MX_SOCK_COL, 1);
           putstr(name, 1);
           putstr(MX_NONE_COL, 1);
    }
}
   