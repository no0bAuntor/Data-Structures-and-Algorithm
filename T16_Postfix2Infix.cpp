#include <iostream>
#include <stack>
using namespace std;

bool isOperand(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return true;
    }

    else
    {
        return false;
    }
}

string postfixToInfix(string postfix)
{
    stack<string> s;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOperand(postfix[i]))
        {
            string op(1, postfix[i]);
            s.push(op);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + postfix[i] + op1 + ")");
        }
    }

    return s.top();
}

int main()
{
    string infix, postfix;
    cout << "Enter postfix Expression: " << endl;
    cin >> postfix;
    cout << "Postfix Expression:" << endl;
    infix = postfixToInfix(postfix);
    cout << endl
         << "Infix Expression:" << endl
         << infix;

    return 0;
}