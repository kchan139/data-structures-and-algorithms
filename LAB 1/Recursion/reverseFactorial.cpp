int reverseFactorial(int n, int i = 1, int fact = 1) 
{
    if (n == 1) return 1;
    
    if (fact > n) return -1;
    
    if (fact == n) return i-1;
    
    return reverseFactorial (n, i + 1, fact * i);
}