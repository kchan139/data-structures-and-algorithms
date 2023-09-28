E removePre ()
{
    Assert (curr != head, "No element");
    
    E it = curr->element;
    
    Link<E> * tmp = curr;
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    curr = tmp->prev;
    
    delete tmp;
    cnt--;
    
    return it;
}
