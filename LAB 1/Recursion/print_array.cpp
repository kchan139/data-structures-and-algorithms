void printArray(int n)
{
    if (!n) cout << 0;
    else 
    {
        printArray(n - 1);
        cout << ", " << n;
    }
}