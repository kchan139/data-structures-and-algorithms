LLNode* reverseList(LLNode* head) {
    LLNode* prev = nullptr;
    LLNode* current = head;
    while (current) {
        LLNode* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

LLNode* foldLinkedList(LLNode* head) {
    if (!head || !head->next) return head;
    
    LLNode* slow = head;
    LLNode* fast = head;
    LLNode* prev = nullptr;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = nullptr;
    LLNode* secondHalf = reverseList(slow);

    LLNode* firstHalf = head;
    LLNode* secondHalfIter = secondHalf;

    LLNode* newHead = new LLNode(0);
    LLNode* current = newHead;

    while (firstHalf && secondHalfIter) {
        current->next = new LLNode(firstHalf->val + secondHalfIter->val);
        current = current->next;

        firstHalf = firstHalf->next;
        secondHalfIter = secondHalfIter->next;
    }

    while (firstHalf) {
        current->next = new LLNode(firstHalf->val);
        current = current->next;
        firstHalf = firstHalf->next;
    }
    while (secondHalfIter) {
        current->next = new LLNode(secondHalfIter->val);
        current = current->next;
        secondHalfIter = secondHalfIter->next;
    }

    return reverseList(newHead->next);
}