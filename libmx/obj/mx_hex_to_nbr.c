#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long nbr = 0;

    for ( int i = 0; hex[i] != '\0'; i++) {

        if (hex[i]>= '0' && hex[i] <= '9')
            nbr = nbr * 16 + (hex[i] - '0');

        else if (hex[i] >= 'A' && hex[i] <= 'F')
            nbr = nbr * 16 + (hex[i] - 'A' + 10);

        else 
            nbr = nbr * 16 + (hex[i] - 'a' + 10);  
    }
    return nbr;
}


