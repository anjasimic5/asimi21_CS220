int sum3or5(int n)
{
    int sum = 0, i = 1;
    while(i < n)
    {
        if (i%3 == 0 || i%5 == 0)
        {
            sum = sum + i;
            i = i + 1;
        }
        else
        {
            i = i + 1;
        }
    }
    
    return sum;
}
