#include "uls.h"

static void xattr_kostul(char *key, const char *path, ssize_t buflen, ssize_t keylen) {
    ssize_t val;

    write(1, "\n", 1);
    while (buflen > 0) {
        mx_print_spaces(8);
        write(1, key, mx_strlen(key));
        val = getxattr(path, key, NULL, 0, XATTR_MAXNAMELEN, XATTR_NOFOLLOW);
        mx_print_spaces(28 - mx_strlen(mx_itoa((int) val)) - mx_strlen(key));
        write(1, mx_itoa((int) val), mx_strlen(mx_itoa((int) val)));
        keylen = strlen(key) + 1;
        buflen -= keylen;
        key += keylen;
        if (buflen > 0)
            write(1, "\n", 1);
    }
}

void mx_p_xattr(t_elem **arr, t_all *ptr, int k, e_flg *flag) {
    ssize_t buflen;
    char *buf;
    char *key;

    if (flag[dog] && (arr[k]->acl == (const void *)64)) {
        buflen = listxattr(arr[k]->path, NULL, 0, XATTR_NOFOLLOW);
        buf = malloc(buflen);
        buflen = listxattr(arr[k]->path, buf, buflen, XATTR_NOFOLLOW);
        key = buf;
        if (buflen > 0)
            xattr_kostul(key, arr[k]->path, buflen, 0);
        free(buf);
    }
}