#include "mypow.h"

int mypow(int x, int y) {
	
	if(y == 0)
	    return 1;
	    
	else if(y % 2 == 0) {
		return mypow(x, y/2.0) * mypow(x, y/2.0);
	}
	
	else{
		return mypow(x, y-1) * x;
	}
	
}
