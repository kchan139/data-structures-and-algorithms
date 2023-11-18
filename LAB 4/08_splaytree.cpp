void rotateLeft(Node* x) 
{
    Node* y = x->pRight;
    x->pRight = y->pLeft;

    if (y->pLeft)
        y->pLeft->pParent = x;

    y->pParent = x->pParent;

    if (!x->pParent)
        root = y;
    else if (x == x->pParent->pLeft)
        x->pParent->pLeft = y;
    else
        x->pParent->pRight = y;

    y->pLeft = x;
    x->pParent = y;
}

void rotateRight(Node* x) 
{
    Node* y = x->pLeft;
    x->pLeft = y->pRight;

    if (y->pRight) 
        y->pRight->pParent = x;
    
    y->pParent = x->pParent;

    if (!x->pParent) 
        root = y;
    else if (x == x->pParent->pLeft) 
        x->pParent->pLeft = y;
    else 
        x->pParent->pRight = y;
    
    y->pRight = x;
    x->pParent = y;
}


void splay(Node* p) 
{
    while (p->pParent) 
    {
        Node* parent = p->pParent;
        Node* grandParent = parent->pParent;

        if (!grandParent) 
        {
            if (p == parent->pLeft)
                rotateRight(parent);
            else
                rotateLeft(parent);
        
        }
        else 
        {
            if (p == parent->pLeft && parent == grandParent->pLeft) 
            {
                rotateRight(grandParent);
                rotateRight(parent);
            } 
            else if (p == parent->pRight && parent == grandParent->pRight) 
            {
                rotateLeft(grandParent);
                rotateLeft(parent);
            } 
            else 
            {
                if (p == parent->pLeft) 
                {
                    rotateRight(parent);
                    rotateLeft(grandParent);
                } 
                else 
                {
                    rotateLeft(parent);
                    rotateRight(grandParent);
                }
            }
        }
    }
    root = p;
}

void insert(int val) 
{
    Node* newNode = new Node(val);
    if (!root) 
    {
        root = newNode;
        return;
    }

    Node* current = root;
    while (true) 
    {
        if (val < current->val) 
        {
            if (current->pLeft)
                current = current->pLeft;
            else 
            {
                current->pLeft = newNode;
                newNode->pParent = current;
                break;
            }
        } 
        else if (val > current->val) 
        {
            if (current->pRight)
                current = current->pRight;
            else 
            {
                current->pRight = newNode;
                newNode->pParent = current;
                break;
            }
        } 
        else 
        {
            if (current->pRight)
                current = current->pRight;
            else 
            {
                current->pRight = newNode;
                newNode->pParent = current;
                break;
            }
        }
    }
    
    splay(newNode);
}
