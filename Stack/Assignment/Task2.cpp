#include <iostream>
#include <stack>

using namespace std;

stack<char> s;

bool ParanthesisBalance(string equation)
{
    for(char c : equation)
    {
        if(c == '(' || c == '{' || c == '[' )
        {
            s.push(c);
        }
        else if(c == ')' || c == '}' || c == ']' )
        {
            if(s.empty())
            {
                return false;
            }
            if(c == ')' && s.top() != '(' || c == '}' && s.top() != '{' || c == ']' && s.top() != ']')
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }
    return s.empty();
}
int main()
{
    string equation;

    cout<<"Enter the equation: ";
    cin>>equation;

    bool balancCheck = ParanthesisBalance(equation);
    if(balancCheck == true)
    {
        cout<<"The paranthesis is balanced!";
    }
    else
    {
        cout<<"The paranthesis is not balanced!";
    }
    
    
    return 0;
}