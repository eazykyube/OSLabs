#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("/dev/random", "r");
    char randomArr[21];
    fgets(randomArr, 21, file);
    printf("%s", randomArr);
    fflush(stdout);
    return 0;
}