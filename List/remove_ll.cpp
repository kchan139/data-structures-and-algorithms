template <typename T> 
void del(List<T> &L,T k)
{
    for (int i = 0; i < L.length(); i++)
    {
        L.moveToPos (i);
        if (L.getValue() == k)
        {
            L.remove();
            i--;
        }
    }
};