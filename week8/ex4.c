#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main(){
	int kb = 1024;
	int mb = 1024*kb;
	struct rusage usage;
	for(int i=0; i<10; i++){
		int *array = malloc(10 * mb);
		memset (array, 0, 10 * mb);
		getrusage(RUSAGE_SELF, &usage);
		printf("Memory usage: %ld\n",usage.ru_maxrss);
		sleep (1);
	}
}