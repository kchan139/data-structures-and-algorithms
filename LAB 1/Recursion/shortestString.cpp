void helper (string& s, int index, string& stack) {
    int len = s.length();
    
    if (index == len)
        return;

    char currentChar = s[index];

    if (!stack.empty() && stack.back() != currentChar)
        stack.pop_back();
    else
        stack.push_back(currentChar);

    helper (s, index + 1, stack);
}

int shortestString(string s) 
{
    string stack = "";
    helper (s, 0, stack);
    return stack.length();
}