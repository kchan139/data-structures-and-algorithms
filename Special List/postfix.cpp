int postfix (string * L, int n)
{
    AStack<int> operands;
    for (int i = 0; i < n; i++)
    {
        if (!(L[i] == "+" || L[i] == "-"))
            operands.push( stoi(L[i]) );
        else 
        {
            int op2 = operands.pop();
            int op1 = operands.pop();
            
            int tmp = (L[i] == "+")? op1 + op2 : op1 - op2;
            operands.push(tmp);
        }
    }
    
    return operands.topValue();
}