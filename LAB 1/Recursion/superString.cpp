int superStringHelper(const string& x, const string& y, int m, int n) 
{
    if (m == 0) return n;
    if (n == 0) return m;

    if (x[m - 1] == y[n - 1])
        return 1 + superStringHelper(x, y, m - 1, n - 1);
    
    return 1 + min(superStringHelper(x, y, m - 1, n),
                   superStringHelper(x, y, m, n - 1));
}

int superString(const string& x, const string& y, int m, int n) 
{
    return superStringHelper(x, y, m, n);
}