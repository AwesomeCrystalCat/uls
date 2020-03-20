#include "uls.h"

static int count_slashes(const char *file) {
    int slash = 0;

    for (int i = 0; file[i] != '\0'; i++) {
        if (file[i] == '_' || file[i] == '.' || file[i] == ',')
            slash++;
    }
        return slash;
}

const void *mx_getacl(const char *filename, struct stat *buff) {
     const void *att; 
     acl_t acl = NULL;
     ssize_t xattr = 0;

     acl = acl_get_file(filename, 0x00000100);
     xattr = listxattr(filename, NULL, 0x0001);
     if (xattr > 0)
         att = (const void *)64;
     else if (acl != NULL && ((buff->st_mode & 0170000) != 0120000)) 
         att = (const void *)43;
     else
         att = (const void *)32;
     acl_free(acl);
     return att;
}

t_elem *mx_getstats(const char *file, const char *dir, e_flg *flag) { //collect all stat of a file;
    t_elem *ptr = (t_elem *)malloc(sizeof(t_elem) * 1);
    struct stat buff;

    ptr->path = mx_get_path(file, dir);
    lstat(ptr->path, &buff);
    ptr->name = mx_strdup(file);
    ptr->mode = mx_set_mode(&buff);
    ptr->inode = mx_itoa(buff.st_ino);
    ptr->acl = mx_getacl(ptr->path, &buff);
    ptr->link = mx_itoa(buff.st_nlink);
    ptr->uid = mx_setuser(&buff, flag);
    ptr->gid = mx_setgrp(&buff, flag);
    ptr->size_i = buff.st_size;
    ptr->size = mx_itoa(buff.st_size);
    ptr->b = buff.st_blocks;
    ptr->bsize = mx_itoa(buff.st_blocks);
    mx_set_time(&buff, ptr, flag);
    return ptr;
}
