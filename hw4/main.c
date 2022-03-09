#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "sum3or5.h"
#include "sequence.h"

bool verifyarg(char input[1024]) {
	for (int i = 0; i < strlen(input); i++ ) {
		if(isdigit(input[i]) == 0)
		    return false;
	}
	return true;
}

int main(int argc, char *argv[]) {
	
	if(argc != 2) {
		printf("Error: enter precisely one integer.\n");
		return 0;
	}
	
	else if(verifyarg(argv[1]) == false) {
		printf("Error: (positive) integer expected.\n");
		return 0;
	}
	
	int n = atoi(argv[1]);
	
	printf("sum3or5 of %d is: %d\n", n, sum3or5(n));
	printf("sequence of %d is: %d\n", n, sequence(n));
}
