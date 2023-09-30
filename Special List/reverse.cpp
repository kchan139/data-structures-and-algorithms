template <typename E>
void reverse(E* L, int n) 
{ 
    Stack<E> * S = new AStack<E> ();

    for (int i = 0; i < n; i++)
        S->push(L[i]);

    for (int i = 0; i < n; i++)
        L[i] = S->pop();
}