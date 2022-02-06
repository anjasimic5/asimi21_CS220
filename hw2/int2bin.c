#include <stdio.h>

void int2bin(int n){
	
	printf("%d = ", n);
	char str[1024];
	int i = 0;
	
	while(n > 0) {
		
		if(n%2 == 0){
			str[i] = '0';
		}
		
		else {
			str[i] = '1';
		}
		n = n / 2;
		i++;
		
	}
	str[i] = '\0';
	while(i > -1) {
		printf("%c", str[i]);
		i = i - 1;
	}
	printf("\n");

}
