#include "uls.h"

static void put_str(const char *str, int fd) {
    int len = mx_strlen(str);

    write(fd, str, len);
}

static void write_colored(const char *name, char *str) {
    put_str(str, 1);
    put_str(name, 1);
    put_str(MX_NONE_COL, 1);
}

static void write_colored_file(t_elem *arr) {
    if (arr->mode[0] == 'd') {
        if (arr->mode[8] == 'w') {
            if (arr->mode[9] == 't' || arr->mode[9] == 'T')
                write_colored(arr->name, MX_GDIR_COL);
            else
                write_colored(arr->name, MX_YDIR_COL);
        }
        else
            write_colored(arr->name, MX_DIR_COL);
    }
    else {
        if (arr->mode[3] == 's')
            write_colored(arr->name, MX_RREG_COL);
        else if (arr->mode[3] == 'x' || arr->mode[6] == 'x')
            write_colored(arr->name, MX_REG_COL);
        else
            write_colored(arr->name, MX_NEXE_COL);
    }
}

void mx_print_colored(t_elem *arr, const char *path) {
    struct stat buff;

    lstat(path, &buff);
    if ((buff.st_mode & MX_IFMT) == MX_IFDIR)
        write_colored_file(arr);
    if ((buff.st_mode & MX_IFMT) == MX_IFBLK)
        write_colored(arr->name, MX_BLK_COL);
    if ((buff.st_mode & MX_IFMT) == MX_IFCHR)
        write_colored(arr->name, MX_CHR_COL);
    if ((buff.st_mode & MX_IFMT) == MX_IFIFO)
        write_colored(arr->name, MX_FIFO_COL);
    if ((buff.st_mode & MX_IFMT) == MX_IFLNK)
        write_colored(arr->name, MX_LNK_COL);
    if ((buff.st_mode & MX_IFMT) == MX_IFREG)
        write_colored_file(arr);
    if ((buff.st_mode & MX_IFMT) == MX_IFSOCK)
        write_colored(arr->name, MX_SOCK_COL);
}
