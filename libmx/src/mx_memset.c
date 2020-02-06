#include "libmx.h"
 void *mx_memset(void *b, int c, size_t len) {
    
    unsigned char *p = (unsigned char *)b;
    unsigned char val = (unsigned char) c;
      if (b == NULL) return NULL;
      if(len == 0) return NULL;
      for(size_t i = 0; i < len; i++, p++) {
        *p = val;
      }

      return b;
  }



