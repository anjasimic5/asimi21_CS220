// Homework 1 Due Monday, January 28
// Anja Simic, CS220 Spring 22
 
#include <stdio.h>

#include "sum3or5.h"
#include "sequence.h"
#include "diamond.h"

int main(void) {
    int n;
    
    printf("Enter a digit: ");
    scanf("%d", &n);
    
    printf("sum3or5 of %d is %d\n", n, sum3or5(n));

    printf("sequence of %d is %d\n", n, sequence(n));

    printf("The longest sequence is %lld\n", longest());
    
    diamond();
} 
