#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
  
  int len = 0;

  for(unsigned long n = nbr; n > 0; n /=16)
    len++;
  char *hex = mx_strnew(len);
    hex[len] = '\0';

    for (int i = 0; nbr > 0; nbr/=16, i++, len--) {
    if (nbr % 16 > 0 && nbr%16 <= 9) {
        hex[len-1] = (nbr % 16) + '0';
    }
    else if (nbr%16 > 9 && nbr%16 < 16) {
      hex[len-1] = (nbr % 16) + 97 - 10;
    }
  else {
    hex = malloc(2);
    hex[0] = '0';
    hex[1] = '\0';
    }
  }
  return hex;
}



