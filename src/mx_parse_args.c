#include "uls.h"

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
                    else
                        data->files[data->fcount++] = mx_strdup(str[i]);
                }
            }
        }
    }
}