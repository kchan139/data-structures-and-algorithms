template <typename T> 
void DuplicationKiller(List<T> &L)
{
    short tmp[16] = {0};
    for (L.moveToStart(); L.currPos() < L.length(); L.next())
        tmp[L.getValue()]++;
        
    for (int i = 0; i < L.length(); i++)
    {
        L.moveToPos(i);
        if (tmp[L.getValue()] > 1)
        {
            L.remove();
            i--;
        }
    }
};