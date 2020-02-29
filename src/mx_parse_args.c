#include "uls.h"

void mx_parse_args(int n, char **str, t_data *data) {
    struct stat buff;

    if (n > 1) {
        printf("here it's\n");
        for (int i = 1; i < n; i++) {
            printf("and here it's\n");
            if (!(str[i][0] == '-')) {
                if (lstat(str[i], &buff) == 0) {
                    if ((buff.st_mode & S_IFMT) == S_IFDIR)
                        data->directs[data->dcount++] = mx_strdup(str[i]);
                    else
                        data->files[data->fcount++] = mx_strdup(str[i]);
                }
            }
        }
    }
    data->directs[data->dcount] = NULL;
    data->files[data->fcount] = NULL;
}