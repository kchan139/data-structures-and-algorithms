#include <iostream>
using namespace std;

typedef struct Item* ptr;
struct Item
{
    double coef; // coefficient
    int exp; // exponent
    ptr next;
};

ptr inputPolynomial ()
{
    ptr head = nullptr;
    double coef; int exp;

    while (cin >> coef >> exp)
    {
        if (!coef) break;

        ptr newHead   = new Item;
        newHead->coef = coef;
        newHead->exp  = exp;
        newHead->next = head;
        head          = newHead;
    }
    
    return head;
}

int main ()
{
    return 0;
}