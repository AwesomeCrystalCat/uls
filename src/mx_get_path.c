#include "uls.h"

const char *mx_get_path(const char *file, const char *dir) {
    const char *path = NULL;
    char *tmp = NULL;

    if (!mx_strcmp(dir, "."))
        path = mx_strdup(file);
    else if (!mx_strcmp(dir, "/")) {
        tmp = mx_strdup("/");
        path = mx_strjoin(tmp, file);
        free(tmp);
    }
    else {
        tmp = mx_strjoin(path, dir);
        path = mx_strjoin(tmp, "/");
        free(tmp);
        tmp = mx_strjoin(path, file);
        free((void *)path);
        path = tmp;
    }
    return path;
}
