#include "uls.h"

char *mx_get_link(const char *name) {
    char buff[1024];
    char *linkname = NULL;
    int len;

    if ((len = readlink(name, buff, 1024)) != -1) {
        buff[len] = '\0';
        linkname = mx_strdup(buff);
    }
    return linkname;
}

static void define_link_path(const char *path,
                            t_data *data, int num, char **str) {
    struct stat buff;
    char *link_path = mx_get_link(path);

    if (lstat(link_path, &buff) == 0) {
        if ((buff.st_mode & MX_IFMT) == MX_IFDIR)
            data->directs[data->dcount++] = mx_strdup(str[num]);
        else
            data->files[data->fcount++] = mx_strdup(str[num]);
    }
    else
        data->files[data->fcount++] = mx_strdup(str[num]);
    free(link_path);
}

void mx_parse_args(int n, char **str, t_data *data) {
    struct stat buff;
    const char *path = NULL;

    if (n > 1) {
        for (int i = 1; i < n; i++) {
            if (!(str[i][0] == '-')) {
                path = mx_get_path(str[i], ".");
                if (lstat(path, &buff) == 0) {
                    if ((buff.st_mode & MX_IFMT) == MX_IFDIR)
                        data->directs[data->dcount++] = mx_strdup(str[i]);
                    else if ((buff.st_mode & MX_IFMT) == MX_IFLNK)
                        define_link_path(path, data, i, str);
                    else
                        data->files[data->fcount++] = mx_strdup(str[i]);
                }
                free((void *)path);
            }
        }
    }
}
