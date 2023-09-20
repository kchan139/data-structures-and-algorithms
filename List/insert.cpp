#include <iostream>
using namespace std;

template <typename T>
class AList
{
    const static int MAX = 20; //the maximum members of the list
    T * data; // keep the list
    int cursor = 0; // keep the position of the cursor
    int size; // the real size of the list

    public:
        AList() { data = new T[MAX];}
       
        void insert (const T & v)
        {
            for (int i = size++; i > cursor; i--)
                data[i] = data[i-1];
            data[cursor] = v;
        }

        void print() const 
        {
            for (int i = 0; i < size; ++i)
                cout << data[i] << ' ';
            cout << endl;
        }
};

int main ()
{
    AList<int> arr;

    for (int i = 0; i < 5; ++i)
    {
        arr.insert(i);
        arr.print();
    }

    return 0;
}