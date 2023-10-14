template <class T>
void SLinkedList<T>::bubbleSort()
{
    bool swapped;
    Node * current;
    Node * next = nullptr;

    do 
    {
        swapped = false;
        current = head;

        while (current->next != next) 
        {
            if (current->data > current->next->data) 
            {
                swap (current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
        
        next = current;
        if (swapped) printList(); 
        
    } while (swapped);
}