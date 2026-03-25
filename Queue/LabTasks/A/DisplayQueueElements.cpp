#include <iostream>
using namespace std;

int n = 10;
int a[10];
int front = -1;
int rear = -1;

bool IsEmpty()
{
    if(front == -1 && rear == -1)
    {
        return true;
    }
    return false;
}
bool IsFull()
{
    if(rear == n -1)
    {
        return true;
    }
    return false;
}
void EnQueue(int data)
{
    if(IsFull())
    {
        cout << "Queue is full"<<endl;
        return;
    }
    if(IsEmpty())
    {
        rear = 0;
        front = 0;
    }
    else
    {
        rear = rear + 1;
    }
    a[rear] = data;
}
int DeQueue()
{
    if(IsEmpty())
    {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    int value = a[front];
    if(rear == front)
    {
        rear = -1;
        front = -1;
    }
    else
    {
        front = front + 1;
    }
    return value;
}
void Display()
{
    if(IsEmpty())
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    
    cout<<"Queue Elements : "<<endl;
    for(int i = front ; i <= rear ; i ++)
    {
        cout<<a[i]<<endl;
    }
}
int main()
{
    EnQueue(2);
    EnQueue(5);
    EnQueue(10);
    DeQueue();
    Display();
    return 0;
}