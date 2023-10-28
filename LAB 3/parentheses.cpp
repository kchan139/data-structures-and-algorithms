bool isValidParentheses (string s)
{
    stack<char> parentheses;
    int len = s.length();

    for (int i = 0; i < len; i++)
    {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{')
            parentheses.push(c);

        else if (c == ')' || c == ']' || c == '}')
        {
            if (parentheses.empty()) return false;
            
            char top = parentheses.top();
            if ((c == ')' && top != '(' )|| 
                (c == ']' && top != '[') ||
                (c == '}' && top != '{'))
                return false;
            
            parentheses.pop();
        }
    }

    return parentheses.empty();
}