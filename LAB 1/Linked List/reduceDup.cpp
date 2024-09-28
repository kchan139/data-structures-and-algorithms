void reduceDuplicate(Node* root) 
{
    if (!root || !root->getNext())
        return;

    Node* prev = root;
    Node* curr = root->getNext();

    while (curr != nullptr)
    {
        if (curr->getData() == prev->getData()) 
        {
            prev->setNext(curr->getNext());
            delete curr;
            curr = prev->getNext();
        } 
        else 
        {
            prev = curr;
            curr = curr->getNext();
        }
    }
}
