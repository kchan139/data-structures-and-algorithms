#include <iostream>
#include <sstream>
using namespace std;

string many_infix_cal (const string & input)
{
	int start_pos = 0, count = 1;
    string str    = input;
    string result = "";

    while ((start_pos = str.find('\n', start_pos)) != string::npos)
    {
        str.replace (start_pos, 1, " ");
        start_pos += 1;
        count++;
    }
    
    int op1 = 0, op2 = 0; char op;
    stringstream ss(str);

    while (count)
    {
        ss >> op1 >> op >> op2;
        switch (op)
        {
            case '+': result += to_string(op1 + op2); break;
            case '-': result += to_string(op1 - op2); break;
            case '*': result += to_string(op1 * op2); break;
            case '/': result += to_string(op1 / op2); break;
            default : break;
        }
        if (count > 1) result += " ";
        count--;
    }

    return result;
}

int main ()
{
	cout << many_infix_cal("10 + 2\n14 * 2\n102 - 10");
	return 0;
}