void reduceDuplicate(Node* root)
{
    if(root && root->getNext() == NULL) 
        return;

    Node* curr = root->getNext(),* prev = root;
    while(curr)
    {
        if(curr->getData() == prev->getData())
        {
            prev->setNext(curr->getNext());
            curr = prev->getNext();
        }
        else
        {
            prev->setNext(curr);
            curr = curr->getNext();
        }
    }
}