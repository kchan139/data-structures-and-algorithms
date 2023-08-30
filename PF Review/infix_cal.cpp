#include <iostream>
#include <sstream>
using namespace std;

string infix_cal (const string & input)
{
	stringstream ss(input);
	int op1, op2; 
	char op;

	ss >> op1 >> op >> op2;
	switch (op)
	{
		case '+': return to_string(op1 + op2);
		case '-': return to_string(op1 - op2);
		case '*': return to_string(op1 * op2);
		case '/': return to_string(op1 / op2);
		default: return "";
	}
}

int main ()
{
	cout << infix_cal("10 + 4");
	return 0;
}