#ifndef LIBMX_H
#define LIBMX_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <wchar.h>
#include <stdbool.h>

char *mx_strnew(const int size);
char *mx_strdup(const char *s1);
char *mx_file_to_str(const char *file);
char **mx_strsplit(const char *s, char c);
char *mx_strndup(const char *s1, size_t n);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);

int mx_strlen(const char *s);
int mx_count_words(const char *str, char c);
int mx_strcmp(const char *s1, const char *s2);

void mx_printint(int n);
void mx_printchar(char c);
void mx_strdel(char **str);
void mx_printstr(const char *s);
void mx_del_strarr(char ***arr);
void mx_print_strarr(char **arr, const char *delim);

#endif
