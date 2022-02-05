// you missed the message about using a long long.  Didn't work
// when I used one million in longest.  -1

#include <stdio.h>
long long sequence(long long n){  // changed to long long
    long long i = 1;   // changed to long long
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
    while (i < 1000001)  // changed this from 100001
    {
        long long tmp = sequence(i);
        // if (dlongest < sequence(i))
        if (dlongest < tmp)
        {
            dlongest = tmp;
            num = i;
        }
        i = i + 1;
    }
    printf("%lld\n", dlongest);
    return num;
}
