#include "uls.h"

void print_spaces(int num) {
    for (int i = 0; i < num; i++) {
        write(1, " ", 1);
    }
}

void mx_dir_parse(e_flg *flag, const char *dir) {
    int cur = 0;
    int all = 0;

    t_all *ptr = malloc(sizeof(t_all));
    ptr->count = mx_files_count(dir, flag);
    
    if (ptr->count) {
        t_elem **dir_args = (t_elem **)malloc(sizeof(t_elem *) * ptr->count);

    mx_read_dir(dir_args, dir, flag);
    mx_sorting(dir_args, ptr, flag);
    mx_cols_and_rows(dir_args, ptr, flag);
    // write(1, dir, mx_strlen(dir));
    // write(1, ":", 1);
    // write(1, "\n", 1);
    if (flag[r_big]) {
        if (mx_strcmp(dir, "/") && mx_strcmp(dir, ".")) {
            write(1, dir, mx_strlen(dir));
            write(1, ":\ntotal:\n", 2);
        }
        // write(1, dir, mx_strlen(dir));//GET LSTAT FOR THE DIRECTORY 
    }
    if (flag[l])
        mx_output_l(dir_args, ptr, flag);
    else if (flag[m])
        mx_output_m(dir_args, ptr, flag);
    else if (flag[one])
        mx_output_1(dir_args, ptr, flag);
    else if (flag[x])
        mx_output_x(dir_args, ptr, flag);
    // else {
    //     for (int k = 0; k < ptr->lines; k++) {
    //         for (int j = 0; j < ptr->count; j++) {
    //             cur = ptr->name_len;
    //             if (j % ptr->lines == k) {
    //                 if (flag[i]) {
    //                     // print_spaces(ptr->inode_n - mx_strlen(dir_args[j]->inode));
    //                     write(1, dir_args[j]->inode, mx_strlen(dir_args[j]->inode));
    //                     write(1, "    ", 1);
    //                     // cur -= ptr->inode_n + 1;
    //                 }
    //                 if (flag[s]) {
    //                     // print_spaces(ptr->bsize_n - mx_strlen(dir_args[j]->bsize));
    //                     write(1, dir_args[j]->bsize, mx_strlen(dir_args[j]->bsize));
    //                     write(1, "    ", 1);
    //                     // cur -= ptr->bsize_n + 1;
    //                 }
    //                 if (isatty(1) == 1) {
    //                     if (flag[g_big])
    //                         mx_print_colored(dir_args[j]->name, dir_args[j]->path);
    //                     else {
    //                         write(1, dir_args[j]->name, mx_strlen(dir_args[j]->name));
    //                         write(1, "    ", 4);
    //                     }
    //                 }
    //                 else {
    //                     write(1, dir_args[j]->name, mx_strlen(dir_args[j]->name));
    //                     write(1, "    ", 4);
    //                     write(1, "\n", 1);
    //                 }
    //                 // cur -= mx_strlen(dir_args[j]->name);
    //                 // print_spaces(cur);
    //             }
    //             // all += ptr->cols;
    //         }
    //         if (k + 1 != ptr->lines)
    //             write(1, "\n", 1);
    //     }
    //     write(1, "\n", 1);
    // }
    write(1, "\n", 1);
    if (flag[r_big]) {
        for (int i = 0; i < ptr->count; i++) {
            if (dir_args[i]->mode[0] == 'd') {
                printf("%s\n", dir_args[i]->path);
                if (dir_args[i]->mode[1] != '-') {
                    if (!(mx_strcmp(dir_args[i]->name, ".") == 0 || mx_strcmp(dir_args[i]->name, "..") == 0))
                        mx_dir_parse(flag, dir_args[i]->path);
                }
                else {
                    write(1, "ls: ", 4);
                    write(1, dir_args[i]->name, mx_strlen(dir_args[i]->name));
                    write(1, ": Permission denied\n", 20);
                }
            }
        }
    }
}
}
