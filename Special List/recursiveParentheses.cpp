bool helper(const string& L, int index, Stack<char>* stack) 
{
    int len = L.length();
    if (index == len)
        return stack->length() == 0;

    char c = L[index];

    if (c == '(')
        stack->push(c);
    else if (c == ')') 
    {
        if (stack->length() == 0 || stack->topValue() != '(')
            return false;
        
        stack->pop();
    }

    return helper(L, index + 1, stack);
}

bool recursiveParentheses(const string& L) 
{
    Stack<char>* stack = new AStack<char>;
    bool result = helper(L, 0, stack);
    delete stack;
    return result;
}