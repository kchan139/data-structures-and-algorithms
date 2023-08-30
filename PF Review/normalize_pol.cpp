#include <iostream>
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
    ptr curr = first;
    ptr back = NULL;
    ptr res  = NULL;
    
    while (curr != NULL) 
    {
        int sumE = curr -> exp;
        if (sumE == 0) return;
        int sumC = curr -> coef;
        
        ptr temp = curr -> next;
    
        while (temp != NULL && temp -> exp == sumE) {
            sumC += temp -> coef;
            ptr flag = temp;
            temp = temp -> next;
            free(flag);
        }
    
        if (sumC == 0) {
            if (back != NULL) back -> next = temp;
            else first = temp;
            free(curr);
        }
        else {
            curr -> coef = sumC;
            curr -> next = res;
            res = curr;
        }
    
        back = temp != NULL ? temp : back;
        curr = temp;
    }
    first = res;
}

int main ()
{
    return 0;
}