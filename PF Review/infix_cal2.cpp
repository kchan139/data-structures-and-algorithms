#include <iostream>
#include <sstream>
using namespace std;

struct action 
{
    string op; // oprator
    int (*func)(int, int); // function pointer to corresponding function
};

int myadd(int x, int y) { return x + y; }
int mymin(int x, int y) { return x - y; }
int mymul(int x, int y) { return x * y; }
int mydiv(int x, int y) { return x / y; }

int infix_cal(const string & input) 
{
    int result = 0;

    stringstream ss(input);
    int op1, op2;
    string op = "";

    ss >> op1 >> op >> op2;
    action actions[] = 
	{
        { "+", myadd },
        { "-", mymin },
        { "*", mymul },
        { "/", mydiv }
    };

    for (int i = 0; i < 4; i++)
        if (actions[i].op == op)
            result = actions[i].func(op1,op2);
        
    return result;
}

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
	// cout << infix_cal("10 + 4");
	cout << many_infix_cal("10 + 2\n14 * 2\n102 - 10");
	return 0;
}