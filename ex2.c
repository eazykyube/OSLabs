#include <stdio.h>
#include <stdlib.h>

int main(void) {
	for (int i = 0; i < 3; i++) {
		fork();
		sleep(5);
	}
	return EXIT_SUCCESS;
}