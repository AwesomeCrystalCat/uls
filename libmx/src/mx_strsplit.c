#include "../inc/libmx.h"

static int malloc_word(const char *s, char c) {
    int i = 0;

    while (s[i] != '\0') {
        if (s[i] == c)
            break;
        else
            i++;
    }
    return i;
}

static char **if_null() {
    char **res = (char **)malloc(sizeof(char *) * (1));

    res[0] = NULL;
    return res;
}

char **mx_strsplit(const char *s, char c) {
    if (s) {
        int i = 0;
        int n = mx_count_words(s, c);
        char **res = (char **) malloc(sizeof(char *) * (n + 1));

        for (int x = 0; x < n && s[i] != '\0'; x++) {
            for (; s[i] == c && s[i] != '\0'; i++);
            while (s[i] != c && s[i] != '\0') {
                res[x] = mx_strnew(malloc_word(&s[i], c));
                for (int j = 0; s[i] != c && s[i] != '\0'; j++, i++) {
                    res[x][j] = s[i];
                }
            }
        }
        res[n] = NULL;
        return res;
    }
    return if_null();
}
