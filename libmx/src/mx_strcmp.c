#include "libmx.h"
int mx_strcmp(const char *s1, const char *s2) {
	if (!s1)
		return -s2[0];
	if(!s2) 
        return s1[0];

	int i = 0;

	if (s1 == s2)
		return 0;

	while (s1[i] != '\0' && s2[i] != '\0') {	
		if(s1[i] != s2[i]) {
			return s1[i] - s2[i];
		}

		i++;
	}
	return s1[i] - s2[i];
}




