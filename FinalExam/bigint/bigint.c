#include "bigint.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

BigInt *make_int(const char *s) {
	
	BigInt *b = malloc(sizeof(BigInt));
	
	b -> n = strlen(s);
	b -> n = strlen(s);    // (*b).n = strlen(s)
	b -> digits = malloc(b -> n);
	
	// copyt digits from s into digits array
	for (int i = 0; i < b->n; i++) {
		b -> digits[i] = s[b -> n - 1 - i] - '0';
	}
	
	return b;
	
}

BigInt *makezero(int n){
	char tmp[n+1];
	memset(tmp, '0', n);
	tmp[n] = 0;      // null terminate the string
	return make_int(tmp);
}

BigInt *add(const BigInt *x, const BigInt *y) {
	const BigInt *longer, *shorter;
	
	if(x->n > y->n){
		longer = x;
		shorter = y;
	}
	else{
		longer = y;
		shorter = x;
	}
	
	BigInt *r = makezero(longer -> n+1);
	
	int c = 0;
	int i= 0;      // loop counter
	
	while( i < shorter -> n){
		byte s = longer -> digits[i] + shorter -> digits[i] + c;
		r -> digits[i] = s % 10;
		c = s / 10;
		i++;
	}
	
	// finish adding in the rest of the longer
	while(i < longer->n) {
		byte s = longer->digits[i] + c;
		r->digits[i] = s % 10;
		c = s / 10;
		i++;
	}
	
	r->digits[i] = c;      // add in final carry
	return r;
	
}

void print_int(const BigInt *b) {
	for(int i = b -> n-2; i > -1; i--){
		printf("%hhd\n", b->digits[i]);
	}
	
}

BigInt *div10(const BigInt *b){
	BigInt *c = malloc(sizeof(BigInt));
	c -> n = b -> n;    // (*b).n = strlen(s)
	c -> digits = malloc(c -> n);
	int m = b -> n;
	
	for (int i =  0; i <= c -> n; i++) {
		c -> digits[m-2] = b -> digits[m-1];
		m--;
	}
	
	return c;
}

BigInt *mul10(const BigInt *b){
	BigInt *c = malloc(sizeof(BigInt));
	c -> n = (b -> n) + 2;    // (*b).n = strlen(s)
	c -> digits = malloc(c -> n);
	
	int m = c -> n;
	for (int i = 0; i < c -> n; i++) {
		c -> digits[m-1] = b -> digits[m-2];
		m--;
	}
	c -> digits[0] = 0;
	
	return c;
}

byte mod10(const BigInt *b){
	byte s = b -> digits[0] % 10;
	return s;
}

int checksum(const BigInt *b){
	int s = 0;
	for(int i = 0; i < b -> n; i++){
		s += b -> digits[i];
	}
	
	return s;
}
