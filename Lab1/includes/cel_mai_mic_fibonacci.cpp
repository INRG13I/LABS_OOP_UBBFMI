int fibonacci(int n)
{
    int a=1, b=1, c=a+b;
    if (n==0)return 1;
    if (n==1)return c;
    while(c<n)
    {
        a=b;
        b=c;
        c=a+b;
    }
    return c;
}