template <class T>
void SLinkedList<T>::bubbleSort()
{
    if (head == nullptr) return;
    
    bool swapped;
    do {
        swapped = false;
        Node * current = head;
        while (current->next != nullptr) {
            if (current->data > current->next->data) {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
        if (swapped) printList();
    } 
    while (swapped);
}