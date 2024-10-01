bool parentheses (const string & L)
{
    Stack<char> * stack = new AStack<char>;
    int len = L.length();
    
    for (int i = 0; i < len; i++)
    {
        char c = L[i];
        if (c == '(')
            stack->push(c);
        else 
        {
            if (!stack->length()) 
                return false;
            
            char top = stack->topValue();
            if (c == ')' && top != '(') 
                return false;
                
            stack->pop();
        }
    }
    
    bool notEmpty = !stack->length();
    delete stack;
    
    return notEmpty;
}