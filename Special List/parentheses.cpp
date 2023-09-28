bool parentheses (const string & L)
{
    AStack<char> stack;
    int len = L.length();
    
    for (int i = 0; i < len; i++)
    {
        char c = L[i];
        if (c == '(')
            stack.push(c);
        else 
        {
            if (!stack.length()) 
                return false;
            
            char top = stack.topValue();
            if (c == ')' && top != '(') 
                return false;
                
            stack.pop();
        }
    }
    
    return !stack.length();
}