// You must use the nodes in the original list and must not modify ListNode's val attribute. 
// Hint: You should complete the function mergeLists first and validate it using our first testcase example

// Merge two sorted lists
ListNode* mergeLists(ListNode* l1, ListNode* l2) 
{
    ListNode dummy (0);
    ListNode *tail = &dummy;

    while (l1 != nullptr && l2 != nullptr) 
    {
        if (l1->val < l2->val) 
        {
            tail->next = l1;
            l1 = l1->next;
        } 
        else 
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = (l1 != nullptr) ? l1 : l2;
    return dummy.next;
}

// Sort and unsorted list given its head pointer
ListNode* mergeSortList(ListNode* head) 
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) 
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = nullptr; 

    ListNode* left = mergeSortList(head);
    ListNode* right = mergeSortList(slow);

    return mergeLists(left, right);
}