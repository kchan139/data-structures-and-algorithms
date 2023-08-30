#include <iostream>
using namespace std;

typedef struct Item * ptr;
struct Item
{
    int value;
    ptr next;
};

ptr inputList ()
{
    ptr head = nullptr;
    int value;
    while (true)
    {
        cin >> value;
        if (value < 0) break;

        ptr newHead = new Item;
        newHead->value = value;
        newHead->next  = head;
        head           = newHead;
    }
    return head;
}

int main ()
{
    cout << "Enter values (negative to stop): " << endl;
    ptr head = inputList();
    ptr tmp  = head;
    while (tmp->next != nullptr)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;    
    }
    cout << endl;
}