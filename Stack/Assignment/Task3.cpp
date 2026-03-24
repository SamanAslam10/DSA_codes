#include <iostream>
#include <stack>

using namespace std;
int PrecedenceCheck(char c)
{
    if(c == '(' || c == ')')
    {
        return 4;
    }
    else if(c == '^')
    {
        return 3;
    }
    else if(c == '*' || c == '/')
    {
        return 2;
    }
    else if(c == '+' || c == '-')
    {
        return 1;
    }
    return 0;
}
int main()
{
    stack<char> s;
    string infix;

    cout<<"Enter the infix expression: ";
    cin>>infix;

    for(char c : infix)
    {
        if(c == '(')
        {
            s.push(c);
        }
        else if(c != '+' && c != '-' && c != '*' && c != '/' && c != '^' && c != '(' && c != ')')
        {
            cout<<c;
        }
        else if(!s.empty() && c == ')')
        {
            do
            {
                cout<<s.top();
                s.pop();
            }while(s.top() != '(');
            if(s.top() == '(')
            {
                s.pop();
            }
        }
        else
        {
            while(!s.empty() && s.top() != '('&& PrecedenceCheck(s.top()) >= PrecedenceCheck(c))
            {
                cout<<s.top();
                s.pop();
            }
            s.push(c);
        }

    }
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    return 0;
}
