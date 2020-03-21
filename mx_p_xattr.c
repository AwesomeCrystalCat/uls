#include "uls.h"

static int weird_kostul(t_elem **arr, t_all *ptr, int k, e_flg *flag) {
    int sp = 0;

    sp += mx_strlen(arr[k]->mode) + 1;
    sp += (mx_l_link(arr, ptr) - mx_strlen(arr[k]->link) + 1);
    sp += mx_strlen(arr[k]->link) + 1;
    sp += mx_strlen(arr[k]->uid);
    sp += (mx_l_uid(arr, ptr) - mx_strlen(arr[k]->uid) + 2);
    sp += mx_strlen(arr[k]->gid);
    sp += (mx_l_gid(arr, ptr) - mx_strlen(arr[k]->gid) + 2);
    sp += (mx_l_size(arr, ptr) - mx_strlen(arr[k]->size));
    sp += mx_strlen(arr[k]->size) - 4;
    return sp;
}

static void xattr_kostul(char *key, const char *path, ssize_t buflen, int sp) {
    ssize_t keylen;
    ssize_t val;

    write(1, "\n", 1);
    while (buflen > 0) {
        mx_print_spaces(8);
        write(1, key, mx_strlen(key));
        val = getxattr(path, key, NULL, 0, XATTR_MAXNAMELEN, XATTR_NOFOLLOW);
        mx_print_spaces(sp - mx_strlen(mx_itoa((int) val)) - mx_strlen(key));
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
    int sp = weird_kostul(arr, ptr, k, flag);

    if (flag[dog] && (arr[k]->acl == (const void *)64)) {
        buflen = listxattr(arr[k]->path, NULL, 0, XATTR_NOFOLLOW);
        buf = malloc(buflen);
        buflen = listxattr(arr[k]->path, buf, buflen, XATTR_NOFOLLOW);
        key = buf;
        if (buflen > 0)
            xattr_kostul(key, arr[k]->path, buflen, sp);
        free(buf);
    }
}