#include "uls.h"
#include <stdio.h>

void mx_dir_parse(int flag, const char *dir) {
    t_all *ptr = malloc(sizeof(t_all));
    ptr->count = mx_files_count(dir, 0, 0);
    
    if (ptr->count) {
    t_elem **dir_args = (t_elem **)malloc(sizeof(t_elem *) * ptr->count);

    mx_read_dir(dir_args, dir, 0, 0);
    mx_quick_elem_sort(dir_args, 0, ptr->count - 1);
    mx_find_name_len(dir_args, ptr);
    mx_get_real_cols(ptr, dir_args); //doesn't work with a single file in the folder; and doesn't work with reccurssion
    ptr->cols = ptr->count / ptr->lines;
    // if (ptr->count % ptr->lines > 0)
    //     ptr->cols++;
    // printf("%d\n", ptr->cols);
    // for (int i = 0; i < ptr->cols; i++) {
    //     for (int j = 0; j < ptr->count; j++) {
    //         if (j % (ptr->count / (ptr->cols - 1)) == i) {
    //             printf("%s\n", dir_args[j]->name);
    //             printf("       ");
    //         }
    //     }
    // }
    // printf("\n");
    // if (flag)
        // printf("%s:\n", dir);
    mx_output_l(dir_args, ptr->count);
    printf("\n");
    if (flag) {
        for (int i = 0; i < ptr->count; i++) {
            if (dir_args[i]->mode[0] == 'd') {
                mx_dir_parse(1, dir_args[i]->name);
            }
        }
    }
    }
}
