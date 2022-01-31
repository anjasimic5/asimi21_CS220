#include <stdio.h>
int sequence(int n){
    int i = 1;
    while(n != 1)
    {
        if (n % 2 == 0)
        {
            n = n /2;
        }
        else
        {
            n = 3 * n + 1;
        }
        i = i + 1;
    }
    
    return i;
}

int longest(void){
    long long i = 1, dlongest = 0, num = 0;
    while (i < 100001)
    {
        if (dlongest < sequence(i))
        {
            dlongest = sequence(i);
            num = i;
        }
        i = i + 1;
    }
    return num;
}
