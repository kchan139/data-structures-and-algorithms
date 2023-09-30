#include <cstring>
template<class T>
T ArrayList<T>::removeAt(int index)
{
    int rmElement = this->data[index];

    int moveCount = this->count - index - 1;
    if (moveCount > 0)
        memmove(this->data + index, this->data + index + 1, moveCount * sizeof(int));

    this->count--;
    return rmElement;
}

template<class T>
bool ArrayList<T>::removeItem(T item)
{
    bool removed = false;
    for (int i = 0; i < this->count; i++)
    {
        if (this->data[i] == item)
        {
            this->removeAt(i);
            removed = true;
        }
    }
    return removed;
}

template<class T>
void ArrayList<T>::clear()
{
    delete [] this->data;
    this->count    = 0;
    this->capacity = 5;
    this->data     = new int[this->capacity];
}
