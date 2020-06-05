#include "libmx.h"

int mx_strncmp1(const char *s1, const char *s2, int n) {
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && n < i)
        i++;
    if (n == i + 1)
        return 0;
    return s1[i] - s2[i];
}
