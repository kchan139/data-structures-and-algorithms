string cleanString(const string &s, int i = 0) 
{
    int size = s.size();
    if (i == size) 
        return "";

    char currChar = s[i];
    
    if (isalpha (currChar))
        return currChar + cleanString (s, i + 1);
    else
        return cleanString (s, i + 1);
}

bool helper (string s, int i = 0)
{
    int size = s.size();
    if (i > size / 2)
       return true;
    
    return s[i] == s[size - i-1] 
            && helper (s, i+1);
}

bool isPalindrome(string str) 
{
    str = cleanString (str);
    return helper (str);
}