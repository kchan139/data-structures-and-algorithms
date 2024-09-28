void LinkedList::partition(int k) 
{
    Node* result  = NULL;
    Node* smaller = new Node(1);
    Node* equal   = new Node(1);
    Node* larger  = new Node(1);
    Node* head1   = equal;
    Node* head2   = larger;
    Node* tmp     = head;
    head          = smaller;

    while(tmp)
    {
        if(tmp->value < k)
        {
            smaller->next = tmp;
            smaller = tmp;
        } 
        else if(tmp->value == k)
        {
            equal->next = tmp;
            equal = tmp;
        }
        else
        {
            larger->next = tmp;
            larger = tmp;
        }
        tmp = tmp->next;
    }
    
    if(head != smaller)
        if(result == NULL) result = head->next;
    
    if(head1 != equal)
    {
        if(result == NULL) 
            result = head1->next;
        else
            smaller->next = head1->next;

        smaller = equal;
    }
 
    if(head2 != larger)
    {
        if(result == NULL) 
            result = head2->next;
        else
            smaller->next = head2->next;
            
        smaller = larger;
    }
    head = result;
    tail = smaller;
}