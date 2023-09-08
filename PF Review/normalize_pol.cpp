#include <iostream>
#include <unordered_map>
using namespace std;

typedef struct Item * ptr;
struct Item
{
    double coef; // coefficient
    int exp; // exponent
    ptr next;
};

void normalizePolynomial(ptr & first)
{
    unordered_map<int, double> pairs;
    ptr tmp = first;
    while (tmp != nullptr)
    {
        pairs[tmp->exp] += tmp->coef;
        tmp = tmp->next;
    }
    
    // for (auto pair : pairs)
    //     cout << pair.first << " " << pair.second << endl;

    tmp = nullptr;
    for (auto pair : pairs)
    {
        if (pair.second)
        {
            ptr newNode = new Item;
            newNode->coef = pair.second;
            newNode->exp  = pair.first;
            newNode->next = tmp;
            tmp = newNode;
        }
    }
    ptr trash = first;
    first = tmp;

    while (trash != nullptr)
    {
        ptr temp = trash;
        trash = trash->next;
        delete temp;
    }
}

void insertItem(ptr& first, double coef, int exp) {
    ptr newItem = new Item;
    newItem->coef = coef;
    newItem->exp = exp;
    newItem->next = nullptr;

    if (!first) {
        first = newItem;
        return;
    }

    ptr curr = first;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = newItem;
}

void printPolynomial(ptr first) {
    ptr curr = first;
    while (curr) {

        cout << "(" << curr->coef << "," << curr->exp << ") ";
        curr = curr->next;
    }
    cout << endl;
}

int main ()
{
    ptr polynomial = nullptr;
    insertItem(polynomial, 2, 3);
    insertItem(polynomial, 1, 4);
    insertItem(polynomial, -2, 3);
    insertItem(polynomial, 0, 0);

    cout << "Original polynomial: ";
    printPolynomial(polynomial);

    cout << "Normalized polynomial: ";
    normalizePolynomial(polynomial);
    printPolynomial(polynomial);

    return 0;
}