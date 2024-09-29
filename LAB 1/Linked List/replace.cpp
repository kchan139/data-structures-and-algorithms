void LinkedList::replace(LinkedList* linked_list, int low, int high) 
{
    if (low < 0) low = 0;
    if (high >= size) high = size - 1;

    Node* prev = nullptr;
    Node* curr = head;

    for (int i = 0; i < low && curr != nullptr; ++i) 
    {
        prev = curr;
        curr = curr->next;
    }

    Node* afterHigh = curr;
    for (int i = low; i <= high && afterHigh != nullptr; ++i)
        afterHigh = afterHigh->next;

    if (prev)
        prev->next = afterHigh;
    else
        head = afterHigh; 

    if (afterHigh == nullptr)
        tail = prev;

    size -= (high - low + 1);

    if (linked_list->head) 
    {
        if (prev)
            prev->next = linked_list->head;
        else
            head = linked_list->head;

        linked_list->tail->next = afterHigh;
        if (!afterHigh)
            tail = linked_list->tail;  
        
        size += linked_list->size;
    }
}