void printHailstone(int number)
{
    /*  
     * STUDENT ANSWER
     */
    if (number == 1) 
    {
        cout << number;
        return;
    }
    
    cout << number << " ";
    if (number & 1)
        printHailstone (number * 3 + 1);
    else 
        printHailstone (number / 2);
}