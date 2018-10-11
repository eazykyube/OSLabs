#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
	int kb = 1024;
	int mb = 1024*kb;
	for(int i=0; i<10; i++){
		int *array = malloc(10 * mb);
		memset (array, 0, 10 * mb);
		sleep (1);
	}
}