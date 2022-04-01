#include "simulate.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

// int seedhack = 0; // global variable

int simulate(int n){
	const int DAYS = 366;
	int cal[DAYS];
	
	// a static variable retains its value (and memory)
	// across function calls
	// static variables are allocated to global memory
	static int seedhack = 0;
	srand(time(NULL) + seedhack++);
	
	memset(cal, 0, DAYS*sizeof(int)); //integer is a dif num of bytes depending on the machine
	
	// assign n birthdays
	int i = 0;
	while(i < n) {
		cal[rand() % DAYS]++;
		i++;
	}
	
	i = 0;
	while(i < DAYS){
		if(cal[i] > 1)
		    return 1;
		i++;
	}
	
	return 0;
	
}
