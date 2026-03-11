#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};
struct Node* ReverseLinkedList(struct Node *Head);
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

    Head = ReverseLinkedList(Head);

    struct Node *temp = NULL;
    temp = Head;
    while(temp != NULL)
    {
        printf("%d , %s", temp->data , "  ");
        temp = temp->link;
    }

    return 0;
}
struct Node* ReverseLinkedList(struct Node *Head)
{
    struct Node *Current = Head;
    struct Node *previous = NULL;
    struct Node *Next = NULL;

    while(Current != NULL)
    {
        Next = Current ->link;
        Current -> link = previous;
        previous = Current;
        Current = Next;
    }
    return previous;

}