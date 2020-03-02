#ifndef ULS_H
#define ULS_H

#define MX_TAB 8

#define MX_IFMT 0170000
#define MX_ISUID 0004000
#define MX_ISGID 0002000
#define MX_ISVTX 0001000
#define MX_IRUSR 0000400
#define MX_IWUSR 0000200
#define MX_IXUSR 0000100
#define MX_IRGRP 0000040
#define MX_IWGRP 0000020
#define MX_IXGRP 0000010
#define MX_IROTH 0000004
#define MX_IWOTH 0000002
#define MX_IXOTH 0000001

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
   f,       //11
   g,       //12
   i,       //13
   l,       //14
   m,       //15
   n,       //16
   o,       //17
   p,       //18
   r,       //19
   s,       //20
   t,       //21
   u,       //22
   x,       //23
   one      //24
} e_flg;

typedef struct s_all {
    char **parsed;
    unsigned int lines;
    unsigned int cols;
    int count;
    int name_len;
    int line_len;
    int spaces;
    int inode_n;
    int bsize_n;
    e_flg *flag;
} t_all;

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
    int numeric;
    char* mode;
    char acl;
    char* link;
    char* uid;
    char* gid;
    unsigned int size_i;
    char* size;
    char* bsize;
    int u_time;
    char* r_time;
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
#include <stdio.h>

int main(int argc, char **argv);
void mx_parse_args(int n, char **str, t_data *data);
t_data *mx_data_init(int argc);
t_total *mx_read_data(int argc, char **argv, t_data *data, e_flg *fl);
void mx_uls(char name[]);
void mx_read_flags(t_total *tot, char ** argv);
void mx_quick_cmp_sort(char **arr, int left, int right);
void mx_quick_elem_sort(t_elem **ptr, int left, int right);
char *mx_set_mode(struct stat *buff);
char *mx_setuser(struct stat *buff, e_flg *flag);
char *mx_setgrp(struct stat *buff, e_flg *flag);
char *mx_set_bsize(struct stat *buff, const char *str);
void mx_set_time(struct stat *buff, t_elem *ptr, e_flg *flag);
t_elem *mx_getstats(const char *file, const char *dir, e_flg *flag);
int mx_files_count(const char *name, e_flg *flag);
void mx_set_stats(t_all *ptr, t_elem **arr);
void mx_find_name_len(t_elem **arr, t_all *ptr, e_flg *flag);
void mx_read_dir(t_elem **dir_args, const char *str, e_flg *flag);
void mx_print_err(char *str);
void mx_swich_flags(int argc, char **argv, t_total *tot,  e_flg *fl);
void mx_prior_all(t_total *tot, e_flg *fl, char **argv);
int mx_get_win_size();
void mx_dir_parse(e_flg *flag, const char *dir);
void mx_get_real_cols(t_all *ptr, t_elem **dir_args, e_flg *flag);
void mx_print_files(t_data *data, e_flg *flag);
void mx_print_dirs(t_data *data, e_flg *flag);
void mx_print_colored(const char *name, const char *path);
void mx_output_l(t_elem **arr, t_all *ptr, e_flg *flag);
void mx_output_1(t_elem **arr, t_all *ptr, e_flg *flag);
void mx_errors_arr(t_total *tot, t_data *data, int argc, char **argv);
void mx_print_errors(t_data *data);
void mx_output_m(t_elem **arr, t_all *ptr, e_flg *flag);
void mx_cols_and_rows(t_elem **dir_args, t_all *ptr, e_flg *flag);
int mx_get_bsize_num(t_all *ptr, t_elem **arr);
int mx_get_inode_num(t_all *ptr, t_elem **arr);
void mx_sorting(t_elem **arr, t_all *ptr, e_flg *flag);
void mx_quick_rev_elem_sort(t_elem **ptr, int left, int right);
void mx_quick_size_sort(t_elem **arr, int left, int right);
void mx_quick_rev_size_sort(t_elem **arr, int left, int right);
const char *mx_get_path(const char *file, const char *dir);
void mx_quick_time_sort(t_elem **arr, int left, int right);
void mx_quick_rev_time_sort(t_elem **arr, int left, int right);
void mx_printer(t_elem **dir_args, t_all *ptr, e_flg *flag);
void mx_output_x(t_elem **arr, t_all *ptr, e_flg *flag);

#endif
