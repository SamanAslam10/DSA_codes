#include <iostream>
#include <stack>

using namespace std;

stack<int> S1;
stack<int> S2;

void EnQueue(int a[] , int n)
{
    for(int i = 0; i < n ; i ++)
    {
        S1.push(a[i]);
    }
}
int DeQueue()
{
    if(S2.empty())
    {
        if(S1.empty())
        {
            cout<<"Queue is empty!";
            return -1;
        }
        else
        {
            while(!S1.empty())
            {
                S2.push(S1.top());
                S1.pop();
            }
        }
    }
    int x = S2.top();
    S2.pop();
    return x;
}
bool IsEmpty()
{
    if(S1.empty() && S2.empty())
    {
        return true;
    }
    return false;
}
int Front()
{
    if(S2.empty())
    {
        if(S1.empty())
        {
            cout<<"Queue is empty!";
            return -1;;
        }
        else
        {
            while(!S1.empty())
            {
                S2.push(S1.top());
                S1.pop();
            }
        }
    }
    int x = S2.top();
    return x;
}
int main()
{
    int array[] = {1,2,3,4,5};
    int n = 5;

    EnQueue(array, n);

    cout << DeQueue() << endl;
    cout << DeQueue() << endl;

    return 0;
}