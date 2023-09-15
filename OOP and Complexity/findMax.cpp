#include <iostream>
using namespace std;

template <typename T>
int findMax (T arr[], int n)
{
    int maxi = 0;
    for (int i = 1; i < n; i++)
        if (arr[maxi] <= arr[i])
            maxi = i;
            
    return maxi;
}

int main ()
{
    return 0;
}