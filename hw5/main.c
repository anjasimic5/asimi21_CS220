#include "simulate.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	//TODO verify command line arguments
	
	int n = atoi(argv[1]);
	int runs = atoi(argv[2]);
	int sum = 0;
	
	for(int i = 0; i < runs; i++){
		sum = sum + simulate(n);
	}

	
	printf("%.2f\n", sum/(double) runs); // cast runs to a double
}
