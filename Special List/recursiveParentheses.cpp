bool recursiveParentheses(const string &L, int index = 0, int balance = 0) {
    /* to check if the string L includes balanced parentheses or not */
    
    int len = L.length();
    if (index == len) return balance == 0;

    if (balance < 0) return false;

    if (L[index] == '(')
        return recursiveParentheses(L, index + 1, balance + 1);
    else if (L[index] == ')') 
        return recursiveParentheses(L, index + 1, balance - 1);
    else
        return recursiveParentheses(L, index + 1, balance);
}
    