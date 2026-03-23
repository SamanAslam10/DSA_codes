#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<char> s;
    string st;

    cout<<"Enter the string: ";
    cin>>st;
    
    for(char c : st)
    {
        s.push(c);
    }

    cout<<"reversed string : ";
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    return 0;
}