template <class T>
T SLinkedList<T>::removeAt(int index)
{
    T removedValue;
    if (!index) 
    {
        Node * tmp = head;
        head = head->next;
        removedValue = tmp->data;

        delete tmp;
        if (count == 1)
            tail = nullptr;
    }
    else
    {
        Node * current = head;
        for (int i = 0; i < index - 1; i++)
            current = current->next;
            
        Node * tmp = current->next;
        current->next = tmp->next;

        if (index == count - 1) 
            tail = current;
        removedValue = tmp->data;
        delete tmp;
    }
    count--;
    return removedValue;
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    Node * current = head;
    Node * prev = nullptr;
    while (current != nullptr) 
    {
        if (current->data == item) 
        {
            if (prev == nullptr) 
            {
                head = current->next;
                delete current;
                if (count == 1)
                    tail = nullptr;
            } 
            else 
            {
                prev->next = current->next;
                if (current == tail)
                    tail = prev;
                delete current;
            }
            count--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

template<class T>
void SLinkedList<T>::clear()
{
    while (head) 
    {
        Node * tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = nullptr;
    count = 0;
}