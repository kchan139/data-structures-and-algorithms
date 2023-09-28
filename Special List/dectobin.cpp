string dec2bin (const unsigned int & x)
{
    AStack<int> bin;
    unsigned int dec = x;
    
    while (dec)
    {
        bin.push(dec % 2);
        dec /= 2;
    }
    
    string result = "";
    while (bin.length())
        result += to_string(bin.pop());
        
    return result;
}