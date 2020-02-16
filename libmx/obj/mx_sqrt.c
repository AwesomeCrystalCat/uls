#include "libmx.h"
int mx_sqrt(int x) {
    int c = 0;
    
    if (x == 1)
    return 1;

    while (c * c < x) {
        c++;
        if (c > 46340) {
        return 0;
        }
    }
    if (c * c != x)
        c = 0;
    return c;

}

