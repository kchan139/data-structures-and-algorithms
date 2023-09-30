LLNode* addLinkedList(LLNode* l0, LLNode* l1) 
{
    LLNode Thread;
    LLNode * curr = & Thread;
    int carry = 0;
    
    while (l0 || l1 || carry)
    {
        int sum = carry;
        if (l0)
        {
            sum += l0->val;
            l0 = l0->next;
        }
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        
        carry = sum / 10;
        curr->next = new LLNode (sum % 10);
        curr = curr->next;
    }
    
    return Thread.next;
}




