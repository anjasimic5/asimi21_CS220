#include <stdio.h>
#include "int2bin.h"

// Good Anja  20/20

int main(void){

    int n;
    printf("Enter an int: ");
    scanf("%d", &n);

    while(n != -1){

        int2bin(n);
        printf("Enter an int: ");
        scanf("%d", &n);
    }

    printf("Bye!\n");

}
