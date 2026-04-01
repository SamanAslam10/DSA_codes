#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
}*front = NULL, *rear = NULL;
bool IsEmpty()
{
    return front == NULL;
}
void EnQueue(int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = NULL;

    if(IsEmpty() == true)
    {
        front = rear = ptr;
        rear -> next = front;
    }

    rear -> next = ptr;
    rear = ptr;
    rear -> next = front;
}
int DeQueue()
{
    int x = -1;

    if(IsEmpty() == true)
    {
        rear = NULL;
        return x;
    }
    struct Node *ptr = front;
    front = front -> next;
    rear -> next = front;

    x = ptr -> data;
    free(ptr);
    ptr = NULL;
    return x;
}
int Front()
{
    return front -> data;
}
int Last()
{
    return rear -> data;
}
void Display()
{
    struct Node *ptr = front;
    if(IsEmpty() == true)
    {
        cout<<"Queue is empty!"<<endl;
        return;
    }
    do
    {
        cout<<ptr -> data<<endl;
        ptr = ptr -> next;
    }
    while(ptr != front);
}
int main()
{
    EnQueue(10);
    EnQueue(20);
    Display();
    DeQueue();
    Display();
    return 0;
}