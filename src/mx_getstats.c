#include "uls.h"

static int count_slashes(const char *file) {
    int slash = 0;

    for (int i = 0; file[i] != '\0'; i++) {
        if (file[i] == '_' || file[i] == '.' || file[i] == ',')
            slash++;
    }
        return slash;
}

// char *mx_rename(const char *file) {
//     char *tmp = NULL;
//     int slash = count_slashes(file);
//     int j = 0;
//     int i = 0;

//     tmp = mx_strnew(mx_strlen(file) - slash);
//     for (; file[i] != '\0'; i++) {
//         if (file[i] != '_' && file[i] != '.' && file[i] != ',') {
//             if (file[i] >= 'a' && file[i] <= 'z')
//                 tmp[j++] = file[i] - 32;
//             else
//                 tmp[j++] = file[i];
//         }
//     }
//     return tmp;
// }

t_elem *mx_getstats(const char *file, const char *dir, e_flg *flag) { //collect all stat of a file;
    t_elem *ptr = malloc(sizeof(t_elem));
    struct stat buff;

    ptr->path = mx_get_path(file, dir);
    lstat(ptr->path, &buff);
    ptr->numeric = buff.st_mode;
    ptr->mode = mx_set_mode(&buff);
    ptr->name = file;
    // if (mx_strcmp(ptr->name, ".") == 0)
    //     ptr->s_name = "*";
    // else if (mx_strcmp(ptr->name, "..") == 0)
    //     ptr->s_name = "**";
    // else
    // ptr->s_name = mx_rename(file);
    ptr->inode = mx_itoa(buff.st_ino);
    // ptr->acl = mx_getacl(file, &buff); //check it later on a mac
    ptr->link = mx_itoa(buff.st_nlink);
    ptr->uid = mx_setuser(&buff, flag);
    ptr->gid = mx_setgrp(&buff, flag);
    ptr->size_i = buff.st_size;
    ptr->size = mx_itoa(buff.st_size);
    //ptr->bsize = mx_set_bsize(&buff, ptr->mode);
    ptr->bsize = mx_itoa(buff.st_blocks);
    mx_set_time(&buff, ptr, flag);
    return ptr;
}
