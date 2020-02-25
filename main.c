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
    t_total *tot = mx_read_data(argc, argv, data);
  
    mx_parse_args(argc, argv, data); //collect data on input if it's
    if (data->directs[0] == NULL && data->files[0] == NULL) //classic output
        mx_dir_parse(0, ".");
    else {
        mx_print_files(data);
        if (data->files[0] != NULL)
            write(1, "\n", 1);
        mx_print_dirs(data);
    }
    return 0;
}
