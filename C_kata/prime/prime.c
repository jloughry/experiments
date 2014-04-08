#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define USAGE "Usage: %s n where n > 0"

void usage (char * name);

void usage (char * name) {
	fprintf(stderr, USAGE, name);
}

int main (int argc, char ** argv) {
	long long n = 0;
	int rc = EXIT_SUCCESS;
	long long factor = 0;
	long long limit = 0;
	int is_prime = 1;

	switch(argc) {
		case 2:
			n = atoll(argv[1]);
			if (n < 0) {
				usage(argv[0]);
				rc = EXIT_FAILURE;
			}
			break;
		default:
			usage(argv[0]);
			break;
	}
	assert(n >= 0);

	if (1 == n) {
		printf("1 is not prime");
		is_prime = 0;
	}
	else {
		factor = 2;
		limit = n;
		while (n > 1 && factor < limit) {
			if (n % factor == 0) {
				if (factor < n) {
					is_prime = 0;
				}
				printf("%lld ", factor);
				n /= factor;
				continue;
			}
			else {
				factor++;
			}
		}
	}
	if (is_prime) {
		printf("%lld is prime", n);
	}
	printf("\n");

	return rc;
}
