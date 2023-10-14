template<class T>
T DLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    Node * tmp = head;
    
    for (int i = 0; i < index; i++)
        tmp = tmp->next;
    
    return tmp->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    Node * tmp = head;
    
    for (int i = 0; i < index; i++)
        tmp=tmp->next;
    
    tmp->data = e;
    tmp = nullptr;
    
    delete tmp;
}

template<class T>
bool DLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    if (!count)
        return true;
    return false;
    
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    int i = 0;
    Node * tmp = head;
    while (tmp != NULL)
    {
        if(tmp->data==item)
            return i;
        
        i++;
        tmp = tmp->next;
    }
    return -1;
}

template<class T>
bool DLinkedList<T>::contains(const T& item) 
{
    /* Check if item appears in the list */
    Node * tmp = head;
    while (tmp != NULL)
    {
        if(tmp->data==item)
            return true;
        
        tmp=tmp->next;
    }  
    return false;
}