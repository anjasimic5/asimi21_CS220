
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
    long long i = 1, longest = 0;
    while (i < 100001)
    {
        if (longest < sequence(i))
        {
            longest = sequence(i);
        }
        i = i + 1;
    }
    return longest;
}
