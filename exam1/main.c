#include <stdio.h>
#include <stdlib.h>
#include "f2c.h"

int main(void){
    char argm[1024];
    printf("Enter a temperature: ");
    scanf("%s", &argm);
    double t = atof(argm);
    printf("%.2f\n", f2c(t));
}