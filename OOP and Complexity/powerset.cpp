#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// O(2^n*log(n))
template <typename T>
vector<vector<T>> powerSet (vector<T> arr) 
{
    vector<vector<T>> result;
    vector<T> tmp;
    int k = 0, x = 0;

    int size = pow(2, arr.size());
    for (int i = 0; i < size; i++)
    {
        k = 0; x = i;
        tmp.clear();

        while (x) 
        {
            if (x & 1) 
                tmp.push_back(arr[k]);
            x = x >> 1;
            k++;
        }
        result.push_back(tmp);
    }
    return result;
}

int main() 
{
    vector<char> input = {'3', '2', '1'};
    vector<vector<char>> result = powerSet(input);

    for (const vector<char>& subset : result) 
    {
        cout << '[';
        for (size_t i = 0; i < subset.size(); ++i) 
        {
            cout << subset[i];
            if (i < subset.size() - 1)
                cout << ',';
        }
        cout << ']' << endl;
    }

    return 0;
}
