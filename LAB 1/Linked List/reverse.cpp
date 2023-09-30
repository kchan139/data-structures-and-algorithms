LLNode* reverseLinkedList(LLNode* head) 
{
    LLNode * prev = nullptr;
    LLNode * curr = head;
    LLNode * next = nullptr;
    
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}