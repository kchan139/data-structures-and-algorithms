bool isOperator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int evaluatePostfix(const string& expression) 
{
    stack<int> operands;

    size_t i = 0;
    while (i < expression.length()) 
    {
        if (expression[i] == ' ') 
        {
            i++;
            continue;
        }

        if (!isOperator(expression[i])) 
        {
            int num = 0;
            while (i < expression.length() && expression[i] != ' ' && !isOperator(expression[i])) 
            {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            operands.push(num);
        } 
        else 
        {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            if (expression[i] == '+')
                operands.push(operand1 + operand2);
            else if (expression[i] == '-')
                operands.push(operand1 - operand2);
            else if (expression[i] == '*')
                operands.push(operand1 * operand2);
            else if (expression[i] == '/')
                operands.push(operand1 / operand2);
            
            i++;
        }
    }

    return operands.top();
}