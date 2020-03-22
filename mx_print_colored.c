#include "uls.h"

static void putstr(const char *str, int fd) {
    int len = mx_strlen(str);

    write(fd, str, len);
}

static void write_colored(const char *name, char *str) {
    putstr(str, 1);
    putstr(name, 1);
    putstr(MX_NONE_COL, 1);
}

static void write_colored_link(t_elem *arr) {
    if (arr->link_type > 0)
        write_colored(arr->name, MX_LNK_COL);
    else
        write_colored(arr->name, MX_BLN_COL);
}

void mx_print_colored(t_elem *arr, const char *path) {
    struct stat buff;

    lstat(path, &buff);
    if ((buff.st_mode & MX_IFMT) == MX_IFDIR)
        write_colored(arr->name, MX_DIR_COL);
    if ((buff.st_mode & MX_IFMT) == MX_IFBLK)
        write_colored(arr->name, MX_BLK_COL);
    if ((buff.st_mode & MX_IFMT) == MX_IFCHR)
        write_colored(arr->name, MX_CHR_COL);
    if ((buff.st_mode & MX_IFMT) == MX_IFIFO)
        write_colored(arr->name, MX_FIFO_COL);
    if ((buff.st_mode & MX_IFMT) == MX_IFLNK)
        write_colored_link(arr);
    if ((buff.st_mode & MX_IFMT) == MX_IFREG)
        write_colored(arr->name, MX_REG_COL);
    if ((buff.st_mode & MX_IFMT) == MX_IFSOCK)
        write_colored(arr->name, MX_SOCK_COL);
}
   