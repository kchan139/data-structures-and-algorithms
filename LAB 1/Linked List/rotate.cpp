LLNode* rotateLinkedList(LLNode* head, int k) 
{
    if (!head || !head->next || k == 0) 
        return head;

    LLNode* curr = head;
    int length = 1;
    while (curr->next) 
    {
        curr = curr->next;
        length++;
    }

    curr->next = head;
    k = k % length;
    if (k == 0) 
    {
        curr->next = nullptr;
        return head;
    }

    int stepsToNewTail = length - k;
    LLNode* newTail = head;
    for (int i = 1; i < stepsToNewTail; i++)
        newTail = newTail->next;

    LLNode* newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
}