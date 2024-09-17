int myArrayToInt(char *str, int n) 
{ 
    /*  
     * STUDENT ANSWER
     */
    if (!n) return 0;
    
    int currentDigit = str[0] - '0';
    
    return currentDigit * pow(10, n - 1) 
            + myArrayToInt(str + 1, n - 1);
}