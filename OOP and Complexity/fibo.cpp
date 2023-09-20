#include <iostream>
using namespace std;

unsigned int fibos[128] = {0, 1, 1};

unsigned int fibo (int n)
{
    if (!fibos[n])
        for (int i = 3; i <= n; i++)
            if (!fibos[i])
                fibos[i] = fibos[i-1] + fibos[i-2];
        
    return fibos[n];
}

int main ()
{
    for (int i = 0; i < 11; i++)
        cout << i << ". " << fibo(i) << endl;

    return 0;
}