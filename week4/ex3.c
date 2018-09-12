#include <stdio.h>
#include <stdlib.h>

#define TRUE 1

int main(void) {
	char command[100];
	while (TRUE) {
		printf("> ");
		scanf("%s", command);
		system(command);
	}
	return EXIT_SUCCESS;
}
