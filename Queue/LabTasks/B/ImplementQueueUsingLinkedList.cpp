#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*front = NULL, *rear = NULL;

bool IsFull()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if(ptr == NULL)
    {
        return true;
    }
    free(ptr);
    return false;
}
bool IsEmpty()
{
    if(front == rear)
    {
        return true;
    }
    return false;
}
int First()
{
    return front -> data;
}
int Last()
{
    return rear -> data;
}
int DeQueue()
{
    int x = -1 ;
    if(IsEmpty() == true)
    {
        return x;
    }
    struct Node *ptr = front;
    front = front -> next;
    if(front == NULL)
    {
        rear = NULL;
    }
    x = ptr -> data;
    free(ptr);
    ptr = NULL;
    return x;
}
void EnQueue(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = NULL;

    if(IsEmpty() == true)
    {
        front = ptr;
        rear = ptr;
        return;
    }
    rear -> next = ptr;
    rear = ptr;
}
void Display()
{
    struct Node *ptr = front;
    while(ptr != NULL)
    {
        cout<<ptr->data<<endl;
        ptr = ptr -> next;
    }
}

int main()
{
    EnQueue(10);
    EnQueue(20);
    EnQueue(30);

    Display();

    DeQueue();

    Display();
    return 0;
}