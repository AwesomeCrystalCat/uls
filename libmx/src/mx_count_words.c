#include "../inc/libmx.h"

static int only_delim(const char *str, char c) {
    int i = 0;

    while (str[i] == c && str[i] != '\0')
        i++;
    if (i == mx_strlen(str))
        return 1;
    return 0;
}

int mx_count_words(const char *str, char c) {
    int i = 0;
    int r = 1;

    if (!str)
        return -1;
    if (only_delim(str, c))
        return 0;
    while (str[i] == c)
        i++;
    while (str[i] != '\0') {
        while (str[i] == c && str[i] != '\0') {
            i++;
            if (str[i] != c && str[i] != '\0')
                r++;
        }
        i++;
    }
    return r;
}
