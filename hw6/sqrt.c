#include "sqrt.h"

double fabs(double n) {
	if (n < 0)
	    n = -n;
	
	return n;
}

#define epsilon .0000001

double sqrt(double n){
	
	double r = n;   // initial guess at the root
	
	while(fabs(n - r*r) > epsilon){
		r = (r + n/r) / 2.0;
	}
	
	return r;
}
