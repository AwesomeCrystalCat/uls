static int count_cols(t_all *ptr, t_elem **dir_args, int s, int i, int one) {
//     ptr->line_len = mx_getwinsize();
//     ptr->name_len = mx_strlen(dir_args[0]->name);
//     int max_line_len = mx_strlen(dir_args[0]->inode) + MX_TAB + mx_strlen(dir_args[0]->bsize) + 1 + mx_strlen(dir_args[0]->name) + MX_TAB;
//     int len_1 = mx_strlen(dir_args[0]->name) + MX_TAB;
//     int cols = 1;
//     printf("len_1 = %d\n", len_1);
//     printf("terminal = %d\n", ptr->line_len);

//     if (one == 1 || max_line_len > ptr->line_len) {
//         return cols;
//     }
//     if (s && i) {
//         if ((max_line_len * ptr->count) < ptr->line_len)
//             cols = ptr->count;
//         else if (max_line_len < ptr->line_len) {
//             for (int j = 1; j < ptr->count; j++) {
//                 if ((max_line_len + mx_strlen(dir_args[j]->name) + mx_strlen(dir_args[j]->inode) + MX_TAB + mx_strlen(dir_args[j]->bsize) + 1) < ptr->line_len) {
//                     cols++;
//                     if ((ptr->line_len - max_line_len + mx_strlen(dir_args[j]->name) + mx_strlen(dir_args[j]->inode) + MX_TAB + mx_strlen(dir_args[j]->bsize) + 1) > 0)
//                         max_line_len = max_line_len + mx_strlen(dir_args[j]->name) + mx_strlen(dir_args[j]->inode) + mx_strlen(dir_args[j]->bsize) + MX_TAB + MX_TAB + 1;
//                 }
//             }
//         }
//     }
//     else {
//         if ((len_1 * ptr->count) <= ptr->line_len)
//             cols = ptr->count;
//         else if (len_1 < ptr->line_len) {
//             for (int j = 1; j < ptr->count; j++) {
//                 if ((len_1 + mx_strlen(dir_args[j]->name)) < ptr->line_len) {
//                     cols++;
//                     if ((ptr->line_len - len_1 + mx_strlen(dir_args[j]->name) + MX_TAB) > 0)
//                         len_1 = len_1 + mx_strlen(dir_args[j]->name) + MX_TAB;
//                 }
//             }
//         }
//     }


    // if (s && i) {
    //     if ((max_line_len * ptr->count) < ptr->line_len)
    //         cols = ptr->count;
    //     else if (max_line_len < ptr->line_len) {
    //         for (int j = 1; j < ptr->count; j++) {
    //             if ((max_line_len + mx_strlen(dir_args[j]->name) + mx_strlen(dir_args[j]->inode) + MX_TAB + mx_strlen(dir_args[j]->bsize) + 1) < ptr->line_len) {
    //                 cols++;
    //                 if ((ptr->line_len - max_line_len + mx_strlen(dir_args[j]->name) + mx_strlen(dir_args[j]->inode) + MX_TAB + mx_strlen(dir_args[j]->bsize) + 1) > 0)
    //                     max_line_len = max_line_len + mx_strlen(dir_args[j]->name) + mx_strlen(dir_args[j]->inode) + mx_strlen(dir_args[j]->bsize) + MX_TAB + MX_TAB + 1;
    //             }
    //         }
    //     }
    // }
    // else {
    //     if ((ptr->name_len * ptr->count) < ptr->line_len)
    //         cols = ptr->count;
    //     else if (len_1 < ptr->line_len) {
    //         for (int j = 1; j < ptr->count; j++) {
    //             if ((len_1 + mx_strlen(dir_args[j]->name)) < ptr->line_len) {
    //                 cols++;
    //                 if ((ptr->line_len - len_1 + mx_strlen(dir_args[j]->name) + MX_TAB) > 0)
    //                     len_1 = len_1 + mx_strlen(dir_args[j]->name) + MX_TAB;
    //             }
    //         }
    //     }
    // }
//     cols = valid_cols(ptr, dir_args, cols);
//     return cols;
// }

// int valid_cols(t_all *ptr, t_elem **dir_args, int cols) {
//     if (cols == 1)
//         return 1;
//     mx_quick_elem_sort(dir_args, 0, ptr->count - 1);
//     ptr->line_len = mx_getwinsize();
//     ptr->name_len = mx_strlen(dir_args[0]->name);
//     for (int i = 0; i < ptr->count; i++)
//         printf("%s\n", dir_args[i]->name);

//     for (int j = 1; j < ptr->count; j++) {
//         if ((ptr->name_len + mx_strlen(dir_args[j]->name)) < ptr->line_len) {
//             cols++;
//                 if ((ptr->line_len - len_1 + mx_strlen(dir_args[j]->name) + MX_TAB) > 0)
//                     len_1 = len_1 + mx_strlen(dir_args[j]->name) + MX_TAB;
//             }
//     }
//     return cols;
// }
 return 0;
}
