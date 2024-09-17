bool match (char *text, char *pat)
{
    if (*text == '\0' && *pat != '\0')
        return false;
    
    if (*pat == '\0')
        return true;
    
    if (*text == *pat)
        return match (text + 1, pat + 1);
    
    return false;
}

bool containsPattern(char* text, char* pat)
{
    /*  
     * STUDENT ANSWER
     */
    if (*text == '\0')
        return false;
    
    if (*text == *pat)
    {
        if (match (text, pat))
            return 1;
        else
            return containsPattern (text + 1, pat);
    }
    
    return containsPattern (text + 1, pat);
}