template<class T>
T SLinkedList<T>::get(int index) 
{
    Node * curr = head;
    for (int i = 0; i < index; i++)
        curr = curr->next;
    return curr->data;
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) 
{
    Node * curr = head;
    for (int i = 0; i < index; i++)
        curr = curr->next;
    curr->data = e;
}

template<class T>
bool SLinkedList<T>::empty() 
{
    return !count;
}

template<class T>
int SLinkedList<T>::indexOf(const T& item)  
{
    Node * curr = head;
    int index = 0;
    while (curr != nullptr) 
    {
        if (curr->data == item)
            return index;
        curr = curr->next;
        index++;
    }
    return -1;
}

template<class T>
bool SLinkedList<T>::contains(const T& item) 
{
    return indexOf(item) != -1;
}