int Fib (int n)
{
    if (n < 2) return 1;
    
    AStack<int> fib(2);
    fib.push(1);
    fib.push(1);
    
    while (n > 1)
    {
        int second = fib.pop();
        int first  = fib.pop();
        int third  = first + second;
        
        fib.push(second);
        fib.push(third);
        n--;
    }
    
    return fib.topValue();
}