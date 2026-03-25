#include <iostream>

using namespace std;

const int sizeofArray = 10;
int a[10];
int front = -1;
int rear = -1;
bool IsEmpty()
{
    if(rear == -1 && front == -1)
    {
        return true;
    }
    return false;
}
bool IsFull()
{
    if((rear +1)% sizeofArray == front)
    {
        cout<<"Queue is full";
        return true;
    }
    return false;
}
int DeQueue()
{
    if(IsEmpty())
    {
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
        front = (front + 1) % sizeofArray;
    }
    return value;
}
void EnQueue(int data)
{
    if(IsFull())
    {
        return;
    }
    else if(IsEmpty())
    {
        rear = 0;
        front = 0;
    }
    else
    {
        rear = (rear + 1) % sizeofArray ;
    }
    a[rear] = data;
}
void Front()
{
    if(!IsEmpty())
    {
        cout<<"First value : "<<a[front]<<endl;
    }
    else
    {
        cout<<"Queue is empty"<<endl;
    }
}
void Rear()
{
    if(!IsEmpty())
    {
        cout<<"Last value : "<<a[rear]<<endl;
    }
    else
    {
        cout<<"Queue is empty"<<endl;
    }
}
int main()
{
    EnQueue(2);
    EnQueue(5);
    EnQueue(10);
    DeQueue();
    Front();
    Rear();
    return 0;
}