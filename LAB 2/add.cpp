template <class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* tmp = new Node();
    tmp->data = e;
    
    if (!tail)
    {
        tail = head = tmp;
        count++;
        return;
    }
    
    tail->next = tmp;
    tmp->previous = tail;
    tail = tmp;
    count++;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    if (index < 0 || index > count)
        return;
        
    if(index==0)
    {
        Node* tmp = new Node(e);  
        tmp->next = head;
        
        if (head != NULL)
            head->previous=tmp;
        else tail = tmp;
        
        head = tmp;
        count++;
        return;
    }
    else if(index==count)
        add(e);
        
    else
    {
        Node* newnode = new Node(e);
        Node* tmp = head;
        for(int i = 0; i < index; i++)
            tmp=tmp->next;
        
        newnode->next       = tmp;
        newnode->previous   = tmp->previous;
        tmp->previous->next = newnode;
        tmp->previous       = newnode;
        
        count++;
        return;
        
    }
    
}

template<class T>
int DLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return count;
}