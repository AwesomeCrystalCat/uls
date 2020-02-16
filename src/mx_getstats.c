#include "uls.h"

const char *getpath(const char *file, char *Directory) {  //still need to change this stuff;
    const char *path = malloc(sizeof(char *));

    if (!mx_strcmp(Directory, "."))
        path = file;
    else {
        path = mx_strjoin(path,Directory);
        path = mx_strjoin(path,"/");
        path = mx_strjoin(path,file);
    }
    return path;
}

t_elem *mx_getstats(const char *file) { //collect all stat of a file;
    t_elem *ptr = malloc(sizeof(t_elem));
    struct stat buff;
    time_t unix_time = time(0);

    lstat(file, &buff);
    ptr->path = getpath(file, ".");
    ptr->name = file;
    ptr->inode = mx_itoa(buff.st_ino);
    ptr->mode = mx_set_mode(&buff);
    // ptr->acl = mx_getacl(file, &buff); //check it later on a mac
    ptr->link = mx_itoa(buff.st_nlink);
    ptr->uid = mx_setuser(&buff, 1);
    ptr->gid = mx_setgrp(&buff, 1);
    ptr->size = mx_itoa(buff.st_size);
    ptr->bsize = mx_set_bsize(&buff, ptr->mode);
    ptr->atime = mx_set_time(&buff, ptr, 0, unix_time);
    return ptr;
}
