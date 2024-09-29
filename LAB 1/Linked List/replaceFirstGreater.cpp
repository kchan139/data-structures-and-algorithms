LLNode* replaceFirstGreater(LLNode* head) 
{
    int cur_pos = 0;
    stack<pair<int, int> > arr;
    
    LLNode * curr = head;
    int count = 0;
    while (curr)
    {
        count++;
        curr = curr->next;
    }
 
    int res[count] = {0};
 
    curr = head;
    while (curr) 
    {
        while (
            !arr.empty()
            && arr.top().second
                   < curr->val) {
 
            res[arr.top().first]
                = curr->val;
            arr.pop();
        }
 
        arr.push(make_pair(
            cur_pos,
            curr->val));
 
        cur_pos++;

        curr = curr->next;
    }
 
    // Return the final result
    curr = head;
    int i = 0;
    while (i < count)
    {
        curr->val = res[i];
        curr = curr->next;
        i++;
    }
    
    return head;
}