#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/* returns 0 for yes and 1 for no, so it can be used directly in shell scripts */

int main(void) {
	char buf[10];
	int rc = 1;

	printf ("Are you sure? [y/N] ");
	fgets (buf, sizeof buf, stdin);
	if ('y' == tolower((int)buf[0])) {
		rc = 0;
	}
	return rc;
}

