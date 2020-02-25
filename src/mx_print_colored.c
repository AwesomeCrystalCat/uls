#include "uls.h"
#include <stdio.h>

void putstr(char const *s, int fd)
{
	int	len;

	len = strlen(s);
	write(fd, s, len);
}

void mx_print_colored(const char *name) {
    struct stat buff;

    lstat(name, &buff);
    if ((buff.st_mode & S_IFMT) == S_IFDIR) {
           write(1, " ", 1);
           putstr(MX_DIR_COL, 1);
           putstr(name, 1);
           putstr(MX_NONE_COL, 1);
           write(1, "\n", 1);
    }
    if ((buff.st_mode & S_IFMT) == S_IFBLK) {
           write(1, " ", 1);
           putstr(MX_BLK_COL, 1);
           putstr(name, 1);
           putstr(MX_NONE_COL, 1);
           write(1, "\n", 1);
    }
    if ((buff.st_mode & S_IFMT) == S_IFCHR) {
           write(1, " ", 1);
           putstr(MX_CHR_COL, 1);
           putstr(name, 1);
           putstr(MX_NONE_COL, 1);
           write(1, "\n", 1);
    }
    if ((buff.st_mode & S_IFMT) == S_IFIFO) {
           write(1, " ", 1);
           putstr(MX_FIFO_COL, 1);
           putstr(name, 1);
           putstr(MX_NONE_COL, 1);
           write(1, "\n", 1);
    }
    if ((buff.st_mode & S_IFMT) == S_IFLNK) {
           write(1, " ", 1);
           putstr(MX_LNK_COL, 1);
           putstr(name, 1);
           putstr(MX_NONE_COL, 1);
           write(1, "\n", 1);
    }
    if ((buff.st_mode & S_IFMT) == S_IFREG) {
           write(1, " ", 1);
           putstr(MX_REG_COL, 1);
           putstr(name, 1);
           putstr(MX_NONE_COL, 1);
           write(1, "\n", 1);
    }
    if ((buff.st_mode & S_IFMT) == S_IFSOCK) {
           write(1, " ", 1);
           putstr(MX_SOCK_COL, 1);
           putstr(name, 1);
           putstr(MX_NONE_COL, 1);
           write(1, "\n", 1);
    }
}
   