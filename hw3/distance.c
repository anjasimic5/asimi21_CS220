#include <math.h>
#include <stdio.h>

#define CTOR M_PI/180

double convert(double x) {
	return x * CTOR;
}

double distance(double lng1, double lat1, double lng2, double lat2) {

	lng1 = convert(lng1);
	lng2 = convert(lng2);
	lat1 = convert(lat1);
	lat2 = convert(lat2);
	
	double R = 6371000 * 0.00062137;
	
	double x = pow(sin((lat2 - lat1)/2), 2) + cos(lat1)*cos(lat2)*pow(sin((lng2 - lng1)/2), 2);
	double y = 2*atan2(sqrt(x), sqrt(1-x));
	
	return R*y;
}
