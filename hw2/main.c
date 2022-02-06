#include <stdio.h>
#include "int2bin.h"

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
