#include "uls.h"
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>

//немного модифицировала мейн для парсинга, но в целом суть та же
//его можно спокойно удалять, если он мешает,
//в целом ни на что не влияет

int main (int argc, char **argv) {
    t_all *ptr = malloc(sizeof(t_all));
    struct winsize w; //в эту струкруту записываются параметры окна
    //структура взята из библиотеки #include <sys/ioctl.h>
    // ioctl(0, 0x540F, &w); //функция достает размеры окна и записывает в структуру
    // printf ("columns %d\n", w.ws_row); //вывод ширины окна
    // if (argc == 1)
    //     mx_uls(".");
    // else
        mx_parse_args(argc, argv, ptr); //простой парсинг аргументов
        // while(--argc) {
        //     printf("%s\n", *++argv);
        //     mx_uls(*argv);
        // }
    for(int i = 0; ptr->parsed[i] != NULL; i++)
        printf("%s\n", ptr->parsed[i]);
    return 0;
}
