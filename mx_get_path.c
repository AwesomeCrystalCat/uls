#include "uls.h"

const char *mx_get_path(const char *file, const char *dir) {  //still need to change this stuff;
    const char *path = malloc(sizeof(char *));

    if (!mx_strcmp(dir, "."))
        path = file;
    else if (!mx_strcmp(dir, "/")) {
        path = mx_strjoin(path, "/");
        path = mx_strjoin(path, file);
    }
    else {
        path = mx_strjoin(path, dir);
        path = mx_strjoin(path,"/");
        path = mx_strjoin(path, file);
    }
    return path;
}
