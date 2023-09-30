void helper (int n, int n_init, int d = -5)
{
    cout << n;
    if (d < 0 && n <= 0)
        d = -d;
        
    if (d > 0 && n >= n_init)
        return;
    else cout << " ";
        
    helper (n + d, n_init, d);
}

void printPattern(int n) 
{
    helper (n, n);
}
