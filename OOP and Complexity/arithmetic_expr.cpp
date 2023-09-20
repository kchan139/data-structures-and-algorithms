#include <iostream>
#include <sstream>
using namespace std;

class Exp
{
    public:
        virtual ~Exp () {}
        virtual int eval () = 0;
        virtual void printPrefix () = 0;
};

class BinExp : public Exp
{
    Exp * left;
    char op;
    Exp * right;
    
    public:
        BinExp (Exp * left, char op, Exp * right) :
        left (left), op (op), right (right) {}

        int eval () override
        {
            switch (op) 
            {
                case '+': return left->eval() + right->eval();
                case '-': return left->eval() - right->eval();
                case '*': return left->eval() * right->eval();
                case '/': return left->eval() / right->eval();
                default : return 0;
            }
        }
        void printPrefix() override 
        {
            cout << op << " ";
            left->printPrefix();
            right->printPrefix();
        }
};

class UnExp : public Exp
{
    char op;
    Exp * exp;

    public:
        UnExp (char op, Exp * exp) : op(op), exp(exp) {}
        int eval () override
        {
            switch (op)
            {
                case '+': return + exp->eval();
                case '-': return - exp->eval();
                default: return 0;
            }
        }
        void printPrefix() override 
        {
            cout << op << ". ";
            exp->printPrefix();
        }
};

class IntLit : public Exp
{
    int value;

    public:
        IntLit (int v) : value (v) {};

        int eval () override { return value; }
        void printPrefix() override { cout << value << " "; }
};