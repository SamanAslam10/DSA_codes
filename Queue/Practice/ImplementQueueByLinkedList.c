#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front = NULL,*rear = NULL;

void EnQueue(int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = NULL;
    if(IsEmpty() == 1)
    {
        front = ptr;
        rear = ptr;
        return;
    }   
    rear -> next = ptr;
    rear = ptr;
}
void DeQueue()
{
    if(IsEmpty() == 1)
    {
        return;
    } 
    struct Node* ptr = front;
    front = front -> next;
    if(front == NULL)
    {
        rear = NULL;
    }
    free(ptr);
    ptr = NULL;
}
int IsEmpty()
{
    if(front == NULL && rear == NULL)
    {
        printf("%s" , "The queue is empty!");
        return 1;
    }
    return 0;
}
int IsFull()
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr == NULL)
    {
        printf("%s" , "The queue is full!");
        return 1;
    }
    return 0;
}
void Display()
{
    struct Node *ptr = front;
    while(ptr != NULL)
    {
        printf("%d", ptr -> data);
        printf("\n");
        ptr = ptr -> next;
    }
}
int main()
{
    EnQueue(40);
    EnQueue(30);
    EnQueue(80);

    Display();

    DeQueue();
    DeQueue();
    EnQueue(50);

    Display();
    printf("%d" , IsEmpty());
    printf("%d" , IsFull());
    return 0;
}