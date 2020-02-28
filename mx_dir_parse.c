#include "uls.h"

void print_spaces(int num) {
    for (int i = 0; i < num; i++) {
        // printf("%d\n", num);
        write(1, " ", 1);
    }
}

int *empty_spaces(t_all *ptr, t_elem **dir_args) {
    int *spaces = (int *)malloc(sizeof(int) * ptr->cols - 1);
    int height = ptr->lines;
    int i = 0;

    for (int cur = 0; cur < ptr->count; i++) {
        spaces[i] = 0;
        int bottom = cur + height;
        for (; cur < bottom && cur < ptr->count; cur++) {
            if (mx_strlen(dir_args[cur]->name) > spaces[i])
                spaces[i] = mx_strlen(dir_args[cur]->name);
        }
        // printf("%d\n", spaces[i]);
    }
    return spaces;
}

void mx_dir_parse(e_flg *flag, const char *dir) {
    t_all *ptr = malloc(sizeof(t_all));
    ptr->count = mx_files_count(dir, flag);
    
    if (ptr->count) {
    t_elem **dir_args = (t_elem **)malloc(sizeof(t_elem *) * ptr->count);
    int *spaces = 0;
    int cur = 0;
    int all = 0;

    mx_read_dir(dir_args, dir, flag);
    mx_quick_elem_sort(dir_args, 0, ptr->count - 1);
    mx_cols_and_rows(dir_args, ptr, flag);
    spaces = empty_spaces(ptr, dir_args);
    if (flag[r_big]) {
        write(1, dir, mx_strlen(dir));
        write(1, ":\ntotal:", 2);
        // write(1, dir, mx_strlen(dir));//GET LSTAT FOR THE DIRECTORY 
    }
    if (flag[l])
        mx_output_l(dir_args, ptr->count, flag);
    else if (flag[m])
        mx_output_m(dir_args, ptr->count, flag);
    else if (flag[one])
        mx_output_1(dir_args, ptr->count, flag); 
    else {
    for (int k = 0; k < ptr->lines; k++) {
        cur = 0;
        for (int j = 0; j < ptr->count; j++, cur++) {
            if (j % ptr->lines == k) {
                if (j / ptr->lines != 0)
                        write(1, "  ", 2);
                if (flag[i]) {
                    write(1, dir_args[j]->inode, mx_strlen(dir_args[j]->inode));
                    write(1, " ", 1);
                }
                if (flag[s]) {
                    write(1, dir_args[j]->bsize, mx_strlen(dir_args[j]->bsize));
                    write(1, " ", 1);
                }
                if (isatty(1) == 1) {
                    if (flag[g_big])
                        mx_print_colored(dir_args[j]->name, dir_args[j]->path);
                    else
                        write(1, dir_args[j]->name, mx_strlen(dir_args[j]->name));
                }
                else
                    write(1, dir_args[j]->name, mx_strlen(dir_args[j]->name));
                // write(1, "\n", 1);
                print_spaces(spaces[j/ptr->lines] - mx_strlen(dir_args[j]->name));
        }
        all += ptr->cols;
    }
    write(1, "\n", 1);
    }
    }
    write(1, "\n", 1);
    if (flag[r_big]) {
        for (int i = 0; i < ptr->count; i++) {
            if (dir_args[i]->mode[0] == 'd') {
                if (!(mx_strcmp(dir_args[i]->name, ".") == 0 || mx_strcmp(dir_args[i]->name, "..") == 0))
                    mx_dir_parse(flag, dir_args[i]->path);
            }
        }
    }
}
}
