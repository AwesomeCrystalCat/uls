#ifndef ULS_H
#define ULS_H

#include "libmx/inc/libmx.h"
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/acl.h>
#include <sys/xattr.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

typedef struct s_all {
    char *parsed;
} t_all;

typedef struct s_total {
    char *all_flags;
    int *arr_for_switch;
    int *priority;
    int num_of_flags; // в массиве входящих данных колличество аргументов с '-'
    int num_of_err;
    int num_of_files;
    int num_of_directs;
} t_total;

typedef struct s_arr_data {
    char ** files;
    char ** directs;
    char ** errors;
} t_data;

typedef struct s_elem {
    const char *path;
    const char *name;
    char* inode;
    char* mode;
    char acl;
    char* link;
    char* uid;
    char* gid;
    char* size;
    char* bsize;
    char* atime;
    char *ctime;
    char *mtime;
} t_elem;

int main(int argc, char **argv);

void mx_print_err(char *str);
void mx_swich_flags(int argc, char **argv, t_total *tot);

void mx_parse_args(int n, char **str, t_all *ptr);
void mx_uls(char name[]);
void mx_read_flags(t_total *tot, char ** argv);
void mx_print_error(t_total *tot, e_errors err);
void mx_quick_cmp_sort(char **arr, int left, int right);
char *mx_set_mode(struct stat *buff);
char *mx_setuser(struct stat *buff, int flag);
char *mx_setgrp(struct stat *buff, int flag);
char *mx_set_bsize(struct stat *buff, const char *str);
char* mx_set_time(struct stat *buff, t_elem *ptr, int flag, time_t time);
t_elem *mx_getstats(const char *file);
int mx_files_count(const char *name);

int mx_strcmp(const char *s1, const char *s2);
char *mx_strcpy(char *dst, const char *src);
char *mx_strdup(const char *str);
char *mx_strjoin(const char *s1, const char *s2);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_itoa(int number);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strndup(const char *s1, size_t n);

#endif

