void processBracket(const string &s, int index, int &unmatchedOpen, int &unmatchedClose) {
    int size = s.size();
    
    if (index >= size) return;
    
    if (s[index] == '(')
        ++unmatchedOpen;
    else if (s[index] == ')') 
    {
        if (unmatchedOpen > 0)
            --unmatchedOpen;
        else
            ++unmatchedClose;
    }
    
    processBracket(s, index + 1, unmatchedOpen, unmatchedClose);
}

int mininumBracketAdd(const string &s) 
{
    int unmatchedOpen = 0;
    int unmatchedClose = 0;
    
    processBracket(s, 0, unmatchedOpen, unmatchedClose);
    
    return unmatchedOpen + unmatchedClose;
}