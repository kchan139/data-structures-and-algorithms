#include <cstring>

template<class T>
void ArrayList<T>::ensureCapacity(int cap)
{
    if (cap >= this->capacity)
    {
        int newCapacity = this->capacity * 1.5;
        int * newData   = new int[newCapacity];

        memmove (newData, this->data, this->count * sizeof(int));
        this->capacity = newCapacity;
        
        delete [] this->data;
        this->data = newData;
    }
}

template <class T>
void ArrayList<T>::add(T e) 
{
    this->ensureCapacity (this->capacity + 1);
    this->data[this->count++] = e;
}

template<class T>
void ArrayList<T>::add(int index, T e)
{
    this->ensureCapacity (this->count + 1);

    int moveCount = this->count - index;
    if (moveCount > 0)
        memmove(this->data + index + 1, this->data + index, moveCount * sizeof(int));

    this->data[index] = e;
    this->count++;
}

template<class T>
int ArrayList<T>::size() 
{
    return count;
}
