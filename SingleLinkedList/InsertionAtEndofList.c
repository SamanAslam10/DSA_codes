#include <stdio.h>
#include <stdlib.h>
// with traversal
struct Node
{
    int data;
    struct Node *link;
};
void InsertAtEnd(struct Node *Head , int data);
int main()
{
    struct Node *Head = NULL;
    Head = (struct Node*)malloc(sizeof(struct Node));
    Head -> data = 10;
    Head -> link = NULL;

    struct Node *Current = NULL;
    Current = (struct Node *)malloc(sizeof(struct Node));
    Current -> data = 20;
    Current -> link = NULL;

    Head->link = Current;

    Current = (struct Node *)malloc(sizeof(struct Node));
    Current -> data = 30;
    Current -> link = NULL;

    Head->link->link = Current;

    Current = (struct Node *)malloc(sizeof(struct Node));
    Current -> data = 40;
    Current -> link = NULL;

    Head->link->link->link = Current;

    InsertAtEnd(Head , 50);
    return 0;
}
void InsertAtEnd(struct Node *Head , int data)
{
    struct Node *temp = NULL;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> link = NULL;

    struct Node *ptr = NULL;
    ptr = Head;
    while(ptr!=NULL)
    {
        ptr = ptr -> link;
    }
    ptr->link = temp;
}