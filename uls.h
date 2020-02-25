#ifndef ULS_H
#define ULS_H

#define MX_TAB 2
#define MX_TERM 182

# define MX_FIFO_COL "\x1b[33m"
# define MX_CHR_COL "\x1b[34;43m"
# define MX_DIR_COL "\x1b[1m\x1b[36m"
# define MX_BLK_COL "\x1b[34;46m"
# define MX_REG_COL "\x1b[0m"
# define MX_LNK_COL "\x1b[35m"
# define MX_SOCK_COL "\x1b[32m"
# define MX_WHT_COL "\x1b[31m"
# define MX_EXE_COL "\x1b[31m"
# define MX_NONE_COL "\x1b[0m"

typedef struct s_all {
    char **parsed;
    unsigned int lines;
    unsigned int cols;
    int count;
    int name_len;
    int line_len;
    int spaces;
} t_all;

typedef enum e_flags {
   dog,     //1
   a_big,   //2
   c_big,   //3
   g_big,   //4
   r_big,   //5
   s_big,   //6
   t_big,   //7
   a,       //8
   c,       //9
   e,       //10
   g,       //11
   i,       //12
   l,       //13
   m,       //14
   n,       //15
   o,       //16
   p,       //17
   r,       //18
   s,       //19
   t,       //20
   u,       //21
   x,       //22
   one      //23
} e_flg;

typedef struct s_total {
    char *all_flags;
    int num_of_flags; // в массиве входящих данных колличество аргументов с '-'
    int num_of_err;
    int num_of_files;
    int num_of_directs;
    int count_dash;
    int size_all_fl;
    e_flg *flags;
} t_total;

typedef struct s_elem {
    const char *path;
    const char *name;
    char *s_name;
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

typedef struct s_arr_data {
    char **files;
    char **directs;
    char **errors;
    int fcount;
    int dcount;
} t_data;

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
#include <sys/ioctl.h>
#include <stdlib.h>

int main(int argc, char **argv);
void mx_parse_args(int n, char **str, t_data *data);
t_data *mx_data_init(int argc);
t_total *mx_read_data(int argc, char **argv, t_data *data);
void mx_uls(char name[]);
void mx_read_flags(t_total *tot, char ** argv);
void mx_quick_cmp_sort(char **arr, int left, int right);
void mx_quick_elem_sort(t_elem **ptr, int left, int right);
char *mx_set_mode(struct stat *buff);
char *mx_setuser(struct stat *buff, int flag);
char *mx_setgrp(struct stat *buff, int flag);
char *mx_set_bsize(struct stat *buff, const char *str);
char* mx_set_time(struct stat *buff, t_elem *ptr, int flag, time_t time);
t_elem *mx_getstats(const char *file);
int mx_files_count(const char *name, int flag_a, int flag_A);
void mx_set_stats(t_all *ptr, t_elem **arr);
void mx_find_name_len(t_elem **arr, t_all *ptr);
void mx_read_dir(t_elem **dir_args, const char *str, int flag_a, int flag_A);
void mx_print_err(char *str);
void mx_swich_flags(int argc, char **argv, t_total *tot,  e_flg *fl);
void mx_prior_all(t_total *tot, e_flg *fl, char **argv);
int mx_get_win_size();
void mx_dir_parse();
void mx_get_real_cols(t_all *ptr, t_elem **dir_args);
void mx_print_files(t_data *data);
void mx_print_dirs(t_data *data);
void mx_print_colored(const char *name);
void mx_output_l(t_elem **arr, int num);

void mx_quicksort(t_elem **arr, int left, int right);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strcpy(char *dst, const char *src);
char *mx_strdup(const char *str);
char *mx_strjoin(const char *s1, const char *s2);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_itoa(int number);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strndup(const char *s1, size_t n);
void mx_printstr(const char *s);
void mx_printchar(char c);

#endif
