#include "uls.h"

void putstr(const char *str, int fd)
{
    int len = mx_strlen(str);
    write(fd, str, len);
}

void write_colored(const char *name, char *str) {
       putstr(str, 1);
       putstr(name, 1);
       putstr(MX_NONE_COL, 1);
}

void mx_print_colored(const char *name, const char *path) {
    struct stat buff;

    lstat(path, &buff);
    if ((buff.st_mode & MX_IFMT) == MX_IFDIR)
       write_colored(name, MX_DIR_COL);
    if ((buff.st_mode & MX_IFMT) == MX_IFBLK)
       write_colored(name, MX_BLK_COL);
    if ((buff.st_mode & MX_IFMT) == MX_IFCHR)
       write_colored(name, MX_CHR_COL);
    if ((buff.st_mode & MX_IFMT) == MX_IFIFO)
       write_colored(name, MX_FIFO_COL);
    if ((buff.st_mode & MX_IFMT) == MX_IFLNK)
       write_colored(name, MX_LNK_COL);
    if ((buff.st_mode & MX_IFMT) == MX_IFREG)
       write_colored(name, MX_REG_COL);
    if ((buff.st_mode & MX_IFMT) == MX_IFSOCK)
       write_colored(name, MX_SOCK_COL);
}
   