#include "uls.h"
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/acl.h>
#include <stdlib.h>

// char mx_getacl(const char *filename, struct stat *buff) {
//     char att; 
//     acl_t acl = NULL;
//     ssize_t xattr = 0;

//     acl = acl_get_file(filename, 0x00000100);
//     xattr = listxattr(filename, 0, 0x0001);
//     if (xattr > 0)
//         att = '@';
//     else if (acl != NULL && ((buff->st_mode & 0170000) != 0120000)) 
//         att = '+';
//     else
//         att = ' ';
//     acl_free(acl);
//     return att;
// }

// void mx_printargc(char *d, int flag) {
//     DIR *dir_ptr;
//     struct dirent *direntp;
// }

int main (int argc, char **argv) {
    t_data *data = mx_data_init(argc);
    e_flg *flag = malloc(24 * sizeof(int));
    for (int j = 0; j < 24; j++)
        flag[j] = 0;
    t_total *tot = mx_read_data(argc, argv, data, flag);

    mx_parse_args(argc, argv, data);
    printf("here\n");
    if (data->directs[0] == NULL && data->files[0] == NULL && data->errors[0] == NULL)
        mx_dir_parse(flag, ".");
    else {
        mx_print_files(data, flag);
        write(1, "\n", 1);
        write(1, "\n", 1);
        mx_print_dirs(data, flag);
    }
    return 0;
}
