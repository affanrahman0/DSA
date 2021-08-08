unsigned long int factorial(unsigned int n)
{
    unsigned int fact=1,i;
    for(i=1;i<=n;i++)
    {
        fact*=i;
    }
    return fact;
}
