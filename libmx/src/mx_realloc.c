#include "libmx.h"
int mx_less(int a, int b) {
    return a < b ? a : b;
}

void *mx_realloc(void *ptr, size_t size) {
    if(ptr == NULL && size != 0)
        return malloc(size);
    if(size == 0) {
        free(ptr);
        ptr = NULL;
        return malloc(malloc_size(0));
    }
    int sz = mx_less(size, malloc_size(ptr));
    void *b = malloc(size);
    if(b == NULL) return NULL;

    mx_memmove(b, ptr, sz);
    free(ptr);
    ptr = NULL;
    return b;

}

