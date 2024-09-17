string reverseSentence(string s) 
{
    if (s.find(' ') == string::npos)
        return s;
    else
    {
        int space = s.find(' ');
        string firstWord = s.substr(0, space);
        string reversed = reverseSentence (s.substr(space + 1));
        return reversed + " " + firstWord;
    }
}