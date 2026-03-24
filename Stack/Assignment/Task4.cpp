#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s;
    string expression;
    int ans = 0;
    int op1;
    int op2;

    cout<<"Enter the postfix expression: ";
    cin>>expression;

    for(char c : expression)
    {
            if(c >= '0' && c <= '9')
            {
                s.push(c-'0');
            }
            else
            {
                op2 = s.top();
                s.pop();
                op1 = s.top();
                s.pop();
                if(c == '+')
                {
                    ans = op1 + op2;
                }        
                else if(c == '-')
                {
                    ans = op1 - op2;
                }  
                else if(c == '*')
                {
                    ans = op1 * op2;
                }  
                else if(c == '/')
                {
                    ans = op1 / op2;
                }  

                s.push(ans);
            }
    }

    cout<<"ans: "<<s.top()<<endl;
    return 0;
}