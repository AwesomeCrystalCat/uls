#include "libmx.h"
double mx_pow(double n, unsigned int pow) {
    if ( pow == 0) {
    return 1;
    }
    
    double rec = 1;
    for(unsigned int i = 0; i < pow; i++) {
        rec *= n;
    }
    return rec;
}

