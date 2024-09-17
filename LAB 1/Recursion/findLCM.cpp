int findGCD(int a, int b)
{
    if (b)
        return findGCD (b, a % b);
    else
        return a;
}

int findLCM(int a, int b)
{
    return (a / findGCD (a, b)) * b;
}