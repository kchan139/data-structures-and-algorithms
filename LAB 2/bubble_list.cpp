template <class T>
void SLinkedList<T>::bubbleSort() {
    for (int curr = count - 1; curr > 0; curr--) {
        Node * currNode = head;
        
        for (int step = 0; step < curr; step++) {
            if (currNode->data > currNode->next->data)
                swap(currNode->data, currNode->next->data);
                
            currNode = currNode->next;
        }
        
        this->printList();
    }
}