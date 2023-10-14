#include <vector>
void helper (ListNode*& tmp)
{
    ListNode* temp = nullptr;
    ListNode* curr = tmp;
    
    while(curr != nullptr)
    {
        temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;
        curr = curr->left;
    }
    
    if (temp) tmp = temp->left;
}

ListNode* reverse(ListNode* head, int a, int b) {
    //To Do
    if(a == b || !head) return head;
    
    
    ListNode* tmp = head;
    ListNode* tmp1 = head;
    for(int i = 1; i <= a - 1; i++)
        tmp = tmp->right;
    
    ListNode * c = tmp->left;
    for(int i = 1; i <= b - 1; i++)
        tmp1 = tmp1->right;
    
    ListNode* d = tmp1->right;
    
    tmp->left = nullptr;
    tmp1->right = nullptr;
    helper(tmp);
    
    tmp->left = c;
    if(c) c->right = tmp;
    
    ListNode* e = tmp;
    while(e->right)
        e = e->right;
    
    e->right = d;
    if(d) d->left = e;
  
    e = tmp;
    while(e->left)
        e = e->left;
    
    head = e;

    return head;   
}