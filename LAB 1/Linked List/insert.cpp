template <class T>
void SLinkedList<T>::add(const T& e) 
{
    Node * newNode = new Node (e, nullptr);
    if (head == nullptr)
        head = tail = newNode;
    else 
    {
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) 
{
    if (index == count)
        add(e);
        
    else if (index == 0)
    {
        Node * newNode = new Node (e, head);
        head = newNode;
        count++;
    }
    else
    {
        Node * newNode = new Node (e, nullptr);
        Node * current = head;

        for (int i = 0; i < index - 1; i++)
            current = current->next;

        newNode->next = current->next;
        current->next = newNode;
        count++;
    }
}

template<class T>
int SLinkedList<T>::size() 
{
    return count;
}