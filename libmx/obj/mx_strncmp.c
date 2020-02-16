#include "libmx.h"

int mx_strncmp(const char *s1, const char *s2, size_t n) {
    if(!s1 || !s2)
        return 0;
    if (n == 0)
        return 0;
	if (s1 == s2)
		return 0;
    unsigned char * s11 = (unsigned char *)s1;
    unsigned char * s22 = (unsigned char *)s2;
    size_t i = 1;
	while (s11 && s22 && (*s11 == *s22) && i < n && i > 0) {	
            s11++;
            s22++;
            i++;

		}
	
	return (*s11 - *s22);
}





