#include "uls.h"

void mx_dir_parse(e_flg *flag, const char *dir) {
    int cur = 0;

    t_all *ptr = malloc(sizeof(t_all));
    // printf("%s\n", dir);
    ptr->count = mx_files_count(dir, flag);
    
    if (flag[r_big] || flag[l] || flag[s] || flag[g_big]) {
        if (flag[r_big]) {
            write(1, dir, mx_strlen(dir));
            write(1, ":\n", 2);
        }
    write(1, "total ", 6); 
        // write(1, dir, mx_strlen(dir));//GET LSTAT FOR THE DIRECTORY 
    }

    if (ptr->count) {
    t_elem **dir_args = (t_elem **)malloc(sizeof(t_elem *) * ptr->count);
    mx_read_dir(dir_args, dir, flag);
    // printf("here\n");
    mx_printstr(mx_print_total(dir_args, ptr));
    write(1, "\n", 1);
    // for (int i = 0; i < ptr->count; i++)
    //         printf("%s\n", dir_args[i]->name);
    //mx_sorting(dir_args, ptr, flag);
    mx_cols_and_rows(dir_args, ptr, flag);
    // printf("%d, %d, %d, %d\n", ptr->lines, ptr->cols, ptr->count, ptr->name_len);
    // write(1, dir, mx_strlen(dir));
    // write(1, ":", 1);
    // write(1, "\n", 1);
    // if (flag[s] || flag[l])
    //     mx_print_total(dir_args, ptr, flag);
    if (flag[l])
        mx_output_l(dir_args, ptr, flag);
    else if (flag[m])
        mx_output_m(dir_args, ptr, flag, 0);
    else if (flag[one])
        mx_output_1(dir_args, ptr, flag, 0);
    else if (flag[x])
        mx_output_x(dir_args, ptr, flag, 0);
    else
        mx_output_c(dir_args, ptr, flag, 0);
    
    write(1, "\n", 1);
    flag[r_big] == 1 ? write(1, "\n", 1) : 0;
    // for (int i = 0; i < ptr->count; i++)
    //         free(dir_args[i]);
    // free(dir_args);
    // free(ptr);

    if (flag[r_big]) {
        for (int i = 0; i < ptr->count; i++) {
            if (dir_args[i]->mode[0] == 'd') {
                if (!(mx_strcmp(dir_args[i]->name, ".") == 0 || mx_strcmp(dir_args[i]->name, "..") == 0)) {
                    if (dir_args[i]->mode[1] != '-' && dir_args[i]->mode[4] != '-' && dir_args[i]->mode[7] != '-') {
                        //printf("%s\n", dir_args[i]->path);
                        mx_dir_parse(flag, dir_args[i]->path);
                        // free(dir_args[i]);
                        // free(ptr);
                        
                    }
                else {
                    write(1, "ls: ", 4);
                    write(1, dir_args[i]->name, mx_strlen(dir_args[i]->name));
                    write(1, ": Permission denied\n", 20);
                }
                // write(1, "\n", 1);
                
                }
            }
            else {
                // free(dir_args[i]);
                // free(ptr);
            }
        }
        // free(dir_args);
        
        // free(ptr);
    }
}
}
