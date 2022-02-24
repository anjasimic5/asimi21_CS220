
#include <stdio.h>
#include <string.h>
#include "distance.h"

#define ZIPLEN 6
#define STATELEN 3
#define CITYLEN 128


int main(int argc, char *argv[]) {
	
	char code[ZIPLEN]; // zipcode
    char state[STATELEN]; // state
    char city[CITYLEN]; // city
    double lng, lat; // longitude and latitude
    unsigned int lc = 0; // line counter
    double lng1, lng2, lat1, lat2;
    char city1[CITYLEN], city2[CITYLEN], state1[STATELEN], state2[STATELEN];
    int n = 0;

    if (argc < 3 || argc > 3) {
        printf("Error: you need to specify precisely two zipcodes.\n");
        return 0;
	}

    char *zcode1 = argv[1], *zcode2 = argv[2];
	
	FILE *f = fopen("../../CS220_data/zips.csv", "r");
	
	if (f == NULL) {
        printf("Error: file not found\n");
        return 0;
    }
    
    while(1) {
		int rc = fscanf(f, "%5s, %2s, %[^,], %lf, %lf", code, state, city, &lng, &lat);

        if (rc == EOF)
            break;
            
        if (strncmp(zcode1, code, 5) == 0) {
			lng1 = lng;
			lat1 = lat;
			strcpy(state1, state);
			strcpy(city1, city);
			n++;
        }
        
        else if (strncmp(zcode2, code, 5) == 0) {
			strcpy(state2, state);
			strcpy(city2, city);
			lng2 = lng;
			lat2 = lat;
			n++;
		}
		
	}
	
	if(n == 2) {
	
	printf("The distance between %s, %s and %s, %s is %.2lf miles.\n", city1, state1, city2, state2, distance(lng1, lat1, lng2, lat2));
	
	}
	
	else {
		printf("Error: enter existing zip codes.\n");
	}
	
	

}
