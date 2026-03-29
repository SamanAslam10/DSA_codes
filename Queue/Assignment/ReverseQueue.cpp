#include <iostream>
#include <stack>
#include <queue>

using namespace std;

queue<int> q;

void ReverseQueue()
{
    stack<int> s;

    if(q.empty())
    {
       cout<<"Queue is empty!";
       return;
    }
    else
    {
         while (!q.empty())
        {
            s.push(q.front());
            q.pop();
        }
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

int main()
{
    q.push(4);
    q.push(6);
    q.push(8);

    ReverseQueue();

    cout<<q.front()<<endl;
    return 0;
}