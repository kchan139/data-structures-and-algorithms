template <class T>
T DLinkedList<T>::removeAt(int index) 
{
    if (index < 0 || index >= count)
        throw out_of_range("Index out of range");

    Node * current = head;
    if (!index) 
    {
        head = current->next;
        if (head)
            head->previous = nullptr;
        else tail = nullptr;
            
        T data = current->data;
        delete current;
        count--;
        return data;
    }

    for (int i = 0; i < index; i++)
        current = current->next;

    Node* previousNode = current->previous;
    Node* nextNode = current->next;
    previousNode->next = nextNode;
    
    if (nextNode)
        nextNode->previous = previousNode;
    else tail = previousNode;

    T data = current->data;
    delete current;
    count--;
    return data;
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item) {
    Node* current = head;
    while (current) 
    {
        if (current->data == item) 
        {
            Node* previousNode = current->previous;
            Node* nextNode = current->next;

            if (previousNode)
                previousNode->next = nextNode;
            else head = nextNode;

            if (nextNode)
                nextNode->previous = previousNode;
            else tail = previousNode;

            delete current;
            count--;
            return true;
        }
        current = current->next;
    }
    return false;
}

template <class T>
void DLinkedList<T>::clear() {
    Node* current = head;
    while (current) 
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    
    head = tail = nullptr;
    count = 0;
}