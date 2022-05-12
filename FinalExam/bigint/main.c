#include "bigint.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    
    // TODO sanitize
    
    BigInt *x = make_int(argv[1]);
    print_int(mul10(x));
    printf("\n");
    print_int(div10(x));
    printf("\n");
    printf("%d\n", mod10(x));
    printf("%d\n", checksum(x));
    free(x);
}
