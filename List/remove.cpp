#include <iostream>
using namespace std;

template <typename T>
class AList
{
    const static int MAXSIZE = 20; //the maximum members of the list
    T * data; // keep the list
    int cursor = 0; // keep the position of the cursor
    int listSize; // the real size of the list

    public:
        AList() { data = new T[MAXSIZE];}
        void print() const 
        {
            for (int i = 0; i < listSize; ++i)
                cout << data[i] << ' ';
            cout << endl;
        }

        void insert (const T & v)
        {
            for (int i = listSize++; i > cursor; i--)
                data[i] = data[i-1];
            data[cursor] = v;
        }

        void remove() 
        {
            if (cursor >= listSize)
                throw out_of_range("Cannot remove element");

            for (int i = cursor; i < listSize - 1; i++)
                data[i] = data[i + 1];
                
            listSize--;
        }
};

int main ()
{
    AList<int> arr;
    for (int i = 5; i > 0; i--)
        arr.insert(i);
    
    arr.print();

    try 
        { arr.remove(); }
    catch (out_of_range)
        { cout << "out of range" << endl; }
    
    arr.print();

    return 0;
}