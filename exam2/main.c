#include <stdio.h>
#include <stdlib.h>
#include "digitsum.h"

int main(int argc, char *argv[]){
	int n = atoi(argv[1]);
	printf("the digitsum of %d is %d\n", n, digitsum(n));
}
