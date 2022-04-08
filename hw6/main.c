#include <stdio.h>
#include <stdlib.h>
#include "sqrt.h"
#include "mypow.h"

int main(int argc, char *argv[]){
	// TODO sanitize the input
	
	if(argc == 1) {
		printf("input at least one value\n");
	}
	
	else if(argc == 2) {
		printf("%f\n", sqrt(atof(argv[1])));
	}
	
	else if(argc == 3) {
		printf("%d\n", mypow(atoi(argv[1]), atoi(argv[2])));
	}
	
	else {
		printf("input a maximum of two values\n");
	}

	
	return 0;
}
