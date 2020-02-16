#include "uls.h"
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/acl.h>
#include <stdlib.h>

static t_total *read_data(int argc, char **argv, t_data *data);
static t_data *data_init(int argc);

int main (int argc, char **argv) {
    t_data *data = data_init(argc);
    t_total *tot = read_data(argc, argv, data);
    t_all *ptr = (t_all *)malloc(sizeof(t_all));
    t_elem **arr = (t_elem **)malloc(sizeof(t_elem *) * (argc - 1));
    struct winsize win;
    int count = 0;

    ioctl(1, TIOCGWINSZ, &win);
    // mx_parse_args(argc, argv, ptr);
    // mx_quick_cmp_sort(ptr->parsed, 0, argc - 2);
    for (int i = 0; ptr->parsed[i] != NULL; i++) {
        arr[i] = mx_getstats(ptr->parsed[i]);
        if (arr[i]->mode[0] == 'd') {
            count = mx_files_count(arr[i]->name);
            t_elem **arr_args = (t_elem **)malloc(sizeof(t_elem *) * count);
            struct dirent *myfile;
            DIR *mydir;
            mydir = opendir(arr[i]->name);
            printf("%s:\ntotal %s", arr[i]->name, arr[i]->bsize);
            while((myfile = readdir(mydir)) != NULL) {
            if (!(strcmp(myfile->d_name, ".") == 0 || strcmp(myfile->d_name, "..") == 0)) {
                printf("\n%s \t", myfile->d_name);
                mx_getstats(myfile->d_name);
            }
            }
            write(1, "\n", 1);
            closedir(mydir);
        }
    }
    write(1, "\n", 1);
    // mx_count_args(ptr); //keep it for folders and reccursion
    for(int i = 0; ptr->parsed[i] != NULL; i++) {
        if (!(arr[i]->mode[0] == 'd')) {
        // printf("%s\n", arr[i]->path);
        printf("%s ", arr[i]->bsize);
        printf("%s ", arr[i]->inode);
        printf("%s ", arr[i]->mode);
        printf("%s ", arr[i]->link);
        printf("%s ", arr[i]->uid);
        printf("%s ", arr[i]->gid);
        printf("%s ", arr[i]->size);
        printf("%s ", arr[i]->ctime);
        printf("%s\n", arr[i]->name);
        }
    }
    return 0;

}


static t_data *data_init(int argc) {
    t_data *data = malloc(sizeof(t_data));
    data->errors = malloc(sizeof(argc));
    data->directs = malloc(sizeof(argc));
    data->files = malloc(sizeof(argc));
    return data;
}

static t_total *read_data(int argc, char **argv, t_data *data) {
    t_total *tot = malloc(sizeof(t_total));
    char *our_flags = "@ACGRSTacegilnoprsu1";
    tot->all_flags = our_flags;

    mx_swich_flags(argc, argv, tot);
    return tot;
}

