#include "uls.h"

static bool comparator(const char *name) {
    bool is_dir = 0;

    if (mx_strcmp(name, ".") == 0)
        is_dir = 1;
    if (mx_strcmp(name, "..") == 0)
        is_dir = 1;
    return is_dir;
}

static const char *make_name(const char* name) {
    int len = mx_strlen(name);
    int i = len;
    const char *buff = NULL;

    for (; i != 0; i--) {
        if (name[i] == '/')
            break;
    }
    buff = mx_strndup(&name[i + 1], len - i - 1);
    return buff;
}

static int count_processor(DIR *mydir, e_flg *flag) {
    struct dirent *myfile;
    int count = 0;

    while((myfile = readdir(mydir)) != NULL) {
        if (flag[a])
            count++;
        else if (flag[a_big]) {
            if (comparator(myfile->d_name) == 0)
                count++;
        }
        else {
            if (myfile->d_name[0] != '.' && comparator(myfile->d_name) == 0)
                count++;
        }
    }
    return count;
}

int mx_files_count(const char *name, e_flg *flag, t_data* data) {
    int count = 0;
    DIR *mydir;
    const char *buff = NULL;

    if ((mydir = opendir(name)) != NULL) {
        mx_print_fname(name, data->cur_dir);
        count = count_processor(mydir, flag);
        closedir(mydir);
    }
    else {
        buff = make_name(name);
        if (data->dcount > 1 || flag[r_big]) {
            write(1, name, mx_strlen(name));
            write(1, ":\n", 2);
        }
        write(2, "uls: ", 5);
        perror(buff);
        free((void *)buff);
    }
    return count;
}
