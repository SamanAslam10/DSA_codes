#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};
struct Node*  DeleteNodeAtParticularPosition(struct Node *Head , int Position);
int main()
{
    int position = 3;
    struct Node *Head = NULL;
    Head = (struct Node*)malloc(sizeof(struct Node));
    Head -> data = 10;
    Head -> link = NULL;

    struct Node *Current = NULL;
    Current = (struct Node *)malloc(sizeof(struct Node));
    Current -> data = 20;
    Current -> link = NULL;

    Head -> link = Current;

    Current = (struct Node *)malloc(sizeof(struct Node));
    Current -> data = 30;
    Current -> link = NULL;

    Head -> link -> link= Current;

    Current = (struct Node *)malloc(sizeof(struct Node));
    Current -> data = 70;
    Current -> link = NULL;

    Head -> link -> link -> link= Current;

    Head = DeleteNodeAtParticularPosition(Head , position);

    struct Node *temp = Head;
    while(temp != NULL)
    {
        printf("%d,%s" , temp -> data , "   ");
        temp = temp -> link;
    }
}

struct Node* DeleteNodeAtParticularPosition(struct Node *Head , int Position)
{
    struct Node *ptr = Head;
    if(Head == NULL)
    {
        printf("%s" , "Nothing to delete! The list is empty.");
    }
    else if(Position == 1)
    {
        Head = ptr -> link;
        free(ptr);
        ptr = NULL;
    }
    else
    {
        struct Node *temp = Head;
        
        while(Position != 1)
        {
            temp = ptr;
            ptr = ptr -> link;
            Position --;
        }
        temp->link = ptr -> link;
        free(ptr);
        ptr = NULL;
    }
    return Head;
}