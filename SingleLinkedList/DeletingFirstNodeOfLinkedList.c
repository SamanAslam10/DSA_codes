#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};
struct Node* DeleteFirstNode(struct Node *Head);
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

    Head = DeleteFirstNode(Head);

    struct Node *ptr = Head;
    while(ptr != NULL)
    {
        printf("%d , %s" , ptr->data , "  " );
        ptr = ptr ->link;
    }
    return 0;
}
struct Node* DeleteFirstNode(struct Node *Head)
{
    struct Node *ptr = Head;

    Head = Head -> link;
    free(ptr);
    return Head;
}