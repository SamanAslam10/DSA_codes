#include <iostream>
#include <queue>
using namespace std;
queue<char> Q1,Q2,Q3;
void Enqueue(int priority , char value)
{
    if(priority == 1)
    {
        Q1.push(value);
    }
    else if(priority == 2)
    {
        Q2.push(value);
    }
    else if(priority == 3)
    {
        Q3.push(value);
    }
    else
    {
        cout<<"Invalid Priority!";
        return;
    }
}
int Dequeue()
{
    int x = -1;
    if(!Q1.empty())
    {
        x=Q1.front();
        Q1.pop();
    }
    else
    {
        if(!Q2.empty())
        {
            x=Q2.front();
            Q2.pop();
        }
        else
        {
            if(!Q3.empty())
            {
                x=Q3.front();
                Q3.pop();
            }
            else
            {
                x = -1;
            }
        }
    }

    return x;
}
int main()
{

    Enqueue(1,'A');
    Enqueue(2,'G');
    Enqueue(3,'D');

    char value = Dequeue();
    cout<<value;

    return 0;
}