#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<char> stack;
    string st;

    cout<<"Enter the string: ";
    cin>>st;
    
    for(char c : st)
    {
        stack.push(c);
    }

    cout<<"reversed string : ";
    while(!stack.empty())
    {
        cout<<stack.top();
        stack.pop();
    }
    return 0;
}