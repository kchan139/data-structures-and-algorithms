int findGCD(int a, int b)
{
    if (b)
        return findGCD (b, a % b);
    else
        return a;
}