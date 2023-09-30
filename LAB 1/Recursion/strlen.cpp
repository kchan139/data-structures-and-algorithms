int strLen(char* str, int d = 0)     
{
    if (str[d] == 0) 
        return d;
    else 
        return strLen(str, d+1);
} 