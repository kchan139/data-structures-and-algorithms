string parenthesesReversal(string s) {
    // STUDENT ANSWER
    if (s.empty()) return s;
    
    stack<char> stk;
    string result;
    
    for (char c : s) {
        if (c != ')')
            stk.push(c);
        else {
            string temp;
            while (!stk.empty() && stk.top() != '(') {
                temp += stk.top();
                stk.pop();
            }
            if (!stk.empty()) stk.pop(); // Remove '('
            
            for (char ch : parenthesesReversal(temp))
                stk.push(ch);
        }
    }
    
    while (!stk.empty()) {
        result = stk.top() + result;
        stk.pop();
    }
    
    return result;
}