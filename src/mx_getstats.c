#include "uls.h"

static void get_link_type(t_elem *ptr) {
    struct stat buff;
    char *link_name = mx_get_link(ptr->path); 

    if (lstat(link_name, &buff) == 0) {
        if ((buff.st_mode & MX_IFMT) == MX_IFDIR) {
            ptr->path_link = mx_strdup(link_name);
            ptr->link_type = 1;
        }
        else
            ptr->link_type = 2;
    }
    else
        ptr->link_type = -1;
    free(link_name);
}

static const void *get_acl_att(const char *filename, struct stat *buff) {
    const void *att; 
    acl_t acl = NULL;
    ssize_t xattr = 0;

    acl = acl_get_file(filename, 0x00000100);
    xattr = listxattr(filename, NULL, 0x0001, 0x0001);
    if (xattr > 0)
        att = (const void *)64;
    else if (acl != NULL && ((buff->st_mode & MX_IFMT) != MX_IFLNK))
        att = (const void *)43;
    else
        att = (const void *)32;
    acl_free(acl);
    return att;
}

static t_elem *init_stat() {
    t_elem *ptr = (t_elem *)malloc(sizeof(t_elem) * 1);

    ptr->path = NULL;
    ptr->name = NULL;
    ptr->mode = NULL;
    ptr->inode = NULL;
    ptr->acl = NULL;
    ptr->link = NULL;
    ptr->uid = NULL;
    ptr->gid = NULL;
    ptr->size_i = 0;
    ptr->size = NULL;
    ptr->b = 0;
    ptr->bsize = NULL;
    ptr->u_time = 0;
    ptr->r_time = NULL;
    ptr->f_time = NULL;
    ptr->link_type = 0;
    ptr->path_link = NULL;
    return ptr;
}

t_elem *mx_getstats(const char *file, const char *dir, e_flg *flag) {
    t_elem *ptr = init_stat();
    struct stat buff;

    ptr->path = mx_get_path(file, dir);
    lstat(ptr->path, &buff);
    ptr->name = mx_strdup(file);
    ptr->mode = mx_set_mode(&buff);
    ptr->mode[0] == 'l' ? get_link_type(ptr) : 0;
    ptr->inode = mx_itoa(buff.st_ino);
    ptr->acl = get_acl_att(ptr->path, &buff);
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
